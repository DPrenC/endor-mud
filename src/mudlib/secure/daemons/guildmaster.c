/*
 * secure/daemons/guildmaster
 * Fichero de funciones para el manejo de los gremios
**/

#include <guild.h>
#include "/secure/wizlevels.h"

#define GUILD_EUIDS ({"asesinos", "aventurero", "conjuradores", "guardabosques", "guerreros",\
                      "hechiceros", "kisalas", "exploradores"})


// ---------------------------------------------------------------------------
// Chequeo de permisos para interactuar con un gremio

private int _check_permissions(string guildname)
{
    object ob = PO;
    if (!ob ||!getuid(ob)) return 0;
    if (query_once_interactive(ob) && IS_CON(getuid(ob))) return 1;
    if (member(GUILD_EUIDS, guildname) < 0) return 0;
    if (getuid(ob) != guildname)
    {
        log_file("GUILD_ERR_PERMISIONS", ctime() + ": PO: " + object_name(PO) + ". Intentó acceder a las tablas de " + guildname + ".\n");
        return raise_error("No tienes permisos para consultar el gremio " + guildname + ".\n"), 0;
    }
    return 1;
}


// ---------------------------------------------------------------------------

// Miembros

public mapping QueryMembers(string guildname)
// Recupera los miembros del gremio <guildname>
{
    mapping members;
    mixed *res;

    if (!sizeof(guildname) || !_check_permissions(guildname)) return 0;
    members = ([:MEMBER_ENTRIES]);
    DBMASTER->Exec("select id, name, entered, level, status from guild_members where guild='" +
                   db_conv_string(guildname) + "' order by id");
    while (res = DBMASTER->Fetch())
    {
        m_add(members, to_string(res[1]), to_int(res[0]), to_int(res[2]), to_int(res[3]), to_int(res[4]));
    }
    return members;
}

public int IsMember(string guildname, string name)
// Devuelve 1 si <name> es miembro de <guildname>.
{
    if (!sizeof(guildname) || !sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select id from guild_members where guild='" + db_conv_string(guildname) + "' and name='" + db_conv_string(name) + "'");
    if (DBMASTER->Fetch()) return 1;
    return 0;
}

public mapping QueryMember(string guildname, string name)
// Devuelve un mapping con la información del miembro seleccionado.
{
    mixed *res;
    mapping m;

    if (!sizeof(guildname) || !sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select id, name, entered, level, status from guild_members where name='" +
                   db_conv_string(name) + "' and guild='" + db_conv_string(guildname) + "'");
    res = DBMASTER->Fetch();
    if (!res) return 0;
    m = ([to_string(res[1]): to_int(res[0]); to_int(res[2]); to_int(res[3]); to_int(res[4])]);
    return m;
}

public int AddMember(string guildname, string name, int level, int stat)
// Añade un miembro al gremio <guildname>
{
    if (!sizeof(guildname) || !sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("insert into guild_members values(default, '" + db_conv_string(guildname) + "', '" + db_conv_string(name) + "', " + time() + ", " + level + ", " + stat + ")");
    return 1;
}

public int RemoveMember(string guildname, string name)
// Borra el miembro <name> del gremio <guildname>
{
    mixed *res;
    int member_id;

    if (!sizeof(guildname) || !sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select id from guild_members where guild='" + db_conv_string(guildname) + "' and name='" + db_conv_string(name) + "'");
    if (!(res = DBMASTER->Fetch())) return 0;
    member_id = to_int(res[0]);
    DBMASTER->Exec("delete from guild_messages where member_id=" + member_id);
    DBMASTER->Exec("delete from guild_members where id=" + member_id);
    return 1;
}

public int ChangeStat(string guildname, string name, int stat)
// Cambia el estado del miembro <name> del gremio <guildname>, al estado especificado por <stat>
{
    if (!sizeof(guildname) ||!sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("update guild_members set status=" + stat + " where name='" + db_conv_string(name) + "' and guild='" + db_conv_string(guildname) + "'");
    return DBMASTER->AffectedRows();
}

public string QueryGuildleader(string guildname)
// Devuelve el guildleader del miembro <guildname>
{
    mixed *res;
    if (!sizeof(guildname) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select name from guild_members where status=" + G_LEADER + " and guild='" + db_conv_string(guildname) + "'");
    if (!(res = DBMASTER->Fetch())) return 0;
    return to_string(res[0]);
}

public string QueryViceleader(string guildname)
// Devuelve el viceleader del gremio <guildname>
{
    mixed *res;
    if (!sizeof(guildname) && !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select name from guild_members where status=" + G_VICELEADER + " and guild='" + db_conv_string(guildname) + "'");
    if (!(res = DBMASTER->Fetch())) return 0;
    return to_string(res[0]);
}

public int ChangeLevel(string guildname, string name, int level)
// Cambia el nivel del miembro <name> del gremio <guildname>, al nivel <level>
{
    if (!sizeof(guildname) || !sizeof(name) ||!_check_permissions(guildname)) return 0;
    DBMASTER->Exec("update guild_members set level=" + level + " where name='" + db_conv_string(name) + "' and guild='" + db_conv_string(guildname) + "'");
    return DBMASTER->AffectedRows();
}

public int UpdateTime(string guildname, string name)
// Actualiza el tiempo de entrada del miembro <name>, del gremio <guildname> a la hora actual
{
    if (!sizeof(guildname) ||!sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("update guild_members set entered=" + time() + " where name='" + db_conv_string(name) + "' and guild='" + db_conv_string(guildname) + "'");
    return DBMASTER->AffectedRows();
}


// ---------------------------------------------------------------------------
// Mensajes de los gremios

public int AddMessage(string guildname, string name, string from_name, string message)
// Añade un mensaje al miembro <name>, del gremio <guildname>
{
    int id;
    mapping mb;
    if (!sizeof(guildname) || !sizeof(name) || !sizeof(from_name) || !sizeof(message) || !_check_permissions(guildname)) return 0;
    if (!(mb = QueryMember(guildname, name))) return 0;
    DBMASTER->Exec("insert into guild_messages values(default, " + mb[name, MEMBER_ID] + ", '" + db_conv_string(from_name) + "', " + time() + ", '" + db_conv_string(message) + "')");
    return 1;
}

public int RemoveMessage(int id)
// elimina el mensaje con id <id>
{
    DBMASTER->Exec("delete from guild_messages where id=" + id);
    return DBMASTER->AffectedRows();
}

public int RemoveMessages(string guildname, string name)
// Elimina todos los mensajes del miembro <name> del gremio <guildname>
{
    mapping mb;
    if (   !sizeof(guildname) || !sizeof(name) || !_check_permissions(guildname)
        || !(mb = QueryMember(guildname, name))) return 0;
    DBMASTER->Exec("delete from guild_messages where member_id=" + mb[name, MEMBER_ID]);
    return DBMASTER->AffectedRows();
}

public mapping QueryMessages(string guildname, string name)
// Recupera todos los mensajes del miembro <name> del gremio <guildname>
{
    mapping mb, msgs;
    mixed *res;

    if (   !sizeof(guildname) ||!sizeof(name) ||!_check_permissions(guildname)
        || !(mb = QueryMember(guildname, name))) return 0;
    msgs = ([:MBR_MSG_ENTRIES]);
    DBMASTER->Exec("select id, from_name, date, message from guild_messages where member_id=" + mb[name, MEMBER_ID]);
    while (res = DBMASTER->Fetch())
    {
        m_add(msgs, to_int(res[0]), to_string(res[1]), to_int(res[2]), to_string(res[3]));
    }
    if (!sizeof(msgs)) return 0;
    return msgs;
}

// ---------------------------------------------------------------------------
// Baneados de gremios

public mapping QueryBanished(string guildname)
// Recupera los personajes baneados del gremio <guildname>
{
    mapping banished;
    mixed *res;
    if (!sizeof(guildname) || !_check_permissions(guildname)) return 0;
    banished = ([:BANISH_ENTRIES]);
    DBMASTER->Exec("select id, name, time, banisher, reason from guild_banished where guild='" + db_conv_string(guildname) + "'");
    while (res = DBMASTER->Fetch())
    {
        m_add(banished, to_string(res[1]), to_int(res[0]), to_int(res[2]), to_string(res[3]), to_string(res[4]));
    }
    return banished;
}

public mapping QueryBanish(string guildname, string name)
// Recupera la información del baneo de <name>, del gremio <guildname>
{
    mixed *res;
    if (!sizeof(guildname) || !sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select id, name, time, banisher, reason from guild_banished where guild='" + db_conv_string(guildname) + "' and name='" + db_conv_string(name) + "'");
    if (!(res = DBMASTER->Fetch())) return 0;
    return ([to_string(res[1]): to_int(res[0]); to_int(res[2]); to_string(res[3]); to_string(res[4])]);
}
public int IsBanished(string guildname, string name)
{
    if (!sizeof(guildname) ||!sizeof(name) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("select id from guild_banished where guild='" + db_conv_string(guildname) + "' and name='" + db_conv_string(name) + "'");
    if (DBMASTER->Fetch()) return 1;
    return 0;
}

public int AddBanish(string guildname, string name, string who, string why)
// Banea al miembro <name>, del gremio <guildname>
{
    int id;
    if (!sizeof(guildname) || !sizeof(name) || !sizeof(who) || !_check_permissions(guildname)) return 0;
    DBMASTER->Exec("insert into guild_banished values(default, '" + db_conv_string(guildname) + "', '" +
                   db_conv_string(name) + "', " + time() + ", '" + db_conv_string(who) + "', '" +
                   (why ? db_conv_string(why) : "no dió ninguna razón") + "')");
    id = DBMASTER->InsertId();
    return id;
}

public int RemoveBanish(string guildname, string name)
// Elimina el baneo de <name>, del gremio <guildname>
{
    mapping bn;
    if (!sizeof(guildname) ||!sizeof(name) || !_check_permissions(guildname)) return 0;
    bn = QueryBanish(guildname, name);
    DBMASTER->Exec("delete from guild_banished where id=" + bn[name, BANISH_ID]);
    return DBMASTER->AffectedRows();
}
