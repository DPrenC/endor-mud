/**
 * simauria /obj/dbmaster
 */


#include <wizlevels.h>
#include "/secure/config.h"
#include "/secure/dbmaster.h"

#define ALLOWED_OBJECTS ({QUIZMASTER, BANKOBJECT})
#define MYSQL_GONE_AWAY"*MySQL server has gone away\n"


private static int handle;

private void remove_connections(int *handles)
{
    int i;
    for (i=sizeof(handles);i--;) db_close(handles[i]);
}

private int check_connection()
// chequea si existe un handle de conexión y si este handle, en
// caso de haberlo, está dentro de la lista de handles de las conexiones activas
// si no hay handle y hay conexiones activas, se asigna alguna de ellas y se cierran las otras
{
    int *handles = db_handles();

    if (!handle || member(handles, handle) < 0)
    {
        if (sizeof(handles))
        // hay conexiones activas
        // Se borran todas menos una, y la restante se asigna al handle actual
        {
            handle = handles[0];
            handles -= ({handle});
            remove_connections(handles);
            return handle;
        }
        else
        {
            handle = db_connect(DB_NAME, DB_USER, DB_PASSWORD);
            db_exec(handle, "set names 'latin1' collate 'latin1_spanish_ci'");

            return handle;
        }
    }
    remove_connections(handles - ({handle}));
    return handle;
}

private varargs int valid_mysql(string fun, string query)
// valida o deniega la ejecución de una función y de una consulta
{
    object prev = PO, pl = TP;
    string euid;
    if (   !prev || !(euid = getuid(prev))
        || (euid != ROOTID && member(ALLOWED_OBJECTS, object_name(prev)) < 0 && pl && !IS_CON(pl)))
    {
        log_file("ILLEGAL_MYSQL",
                 ctime() + ": " + getuid(pl) +
                 " intentó ejecutar la función " + fun +
                 (query? "con la sentencia: " + query : "") + ".\n\n");
        if (living(pl)) tell_object(pl, "¡No tienes permiso para hacer esto!\n");
        return 0;
    }
    // dtell("kastwey", "prev: " + object_name(prev) + ". pl: " + object_name(pl) + ".\n");
    return 1;
}


create()
{
    check_connection();
}

public int InsertId()
{
    int i, res;
    string msg_error;

    if (!valid_mysql("db_insert_id")) return 0;
    for (i=0;i<2;i++)
    {
        check_connection();
        if (msg_error = catch(res = db_insert_id(handle)))
        {
            if (msg_error == MYSQL_GONE_AWAY && !i) continue;
            raise_error(msg_error);
            return 0;
        }
        else break;
    }
    return res;
}

public int Exec(string consulta)
{
    string msg_error;
    int res, i;

    if (!valid_mysql("db_exec", consulta)) return 0;
    // este bucle es por si se produce un error MYSQL_GONE_AWAY, repetir
    // la operación dos veces a ver si a la segunda cuela.
    for (i=0;i<2;i++)
    {
        check_connection();
        if (msg_error = catch(res = db_exec(handle, consulta)))
        {
            if (msg_error == MYSQL_GONE_AWAY && !i) continue;
            raise_error(msg_error);
            return 0;
        }
        else break;
    }
    if (!res) return raise_error(db_error(handle)), 0;
    return handle;
}

public mixed *Fetch()
{
    int i;
    mixed *res;
    string msg_error;

    if (!valid_mysql("db_fetch")) return 0;
    for (i=0; i<2; i++)
    {
        if (!check_connection()) return 0;
        if (msg_error = catch(res = db_fetch(handle)))
        // error
        {
            if (msg_error == MYSQL_GONE_AWAY) continue;
            raise_error(msg_error);
            return 0;
        }
        else break;
    }
    return res;
}

public int AffectedRows()
{
    int i, res;
    string msg_error;

    if (!valid_mysql("db_affected_rows")) return 0;
    for (i=0; i<2; i++)
    {
        if (!check_connection()) return -1;
        if (msg_error = catch(res = db_affected_rows(handle)))
        // error
        {
            if (msg_error == MYSQL_GONE_AWAY) continue;
            raise_error(msg_error), 0;
        }
        else break;
    }
    return res;
}

public string Error()
{
    int i;
    string msg_error, res;

    if (!valid_mysql("db_error")) return 0;
    for (i=0; i<2; i++)
    {
        if (!check_connection()) return 0;
        if (msg_error = catch(res = db_error(handle)))
        // error
        {
            if (msg_error == MYSQL_GONE_AWAY) continue;
            return raise_error(msg_error), 0;
        }
        else break;
    }
    return res;
}

public int remove()
{
    remove_connections(db_handles());
    destruct(TO);
    return !TO;
}
