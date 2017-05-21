/***
fichero: _calcular.c
Autor: kastwey
Descripción: Calcula la xp necesaria para avanzar en jugador o gremio.
Creación: 22/01/2006
***/

#include <guild.h>
#define MSG_SPEAK  "all_speak:"
#define TIFLO(x,i) (x->QueryTiflo() ? MSG_SPEAK + i : i)
#define LEVEL      "/std/guild/level"
#define GREMIO     0
#define JUGADOR    1




/*
Esta función devuelve información sobre el estado de un player referente a su
nivel de gremio o de jugador.
*/
private string _query_player_level_info(int type)
{
    object pl = TP;
    // para no llamar mucho a this_player()
    string msg = ""; // el mensaje que se enviará al final de la función
    int xp = (type == JUGADOR ?pl->QueryXP() : pl->QueryGuildXP());
    // la xp de gremio o jugador, dependiendo del type pasado como parámetro
    int qp = QUESTMASTER->QueryQuestPoints(pl); // puntos de quest
    int level = (type == JUGADOR ? pl->QueryLevel() : pl->QueryGuildLevel());
    // nivel de gremio o jugador, dependiendo del type.
    int level_w_qp = (QUESTMASTER->QueryTotalQuestPoints() > qp ?
                      LEVEL->QPtoLevel(qp) : level);
    // el nivel que podría alcanzar con los puntos de quest actuales
    int advance_level = xp2level(xp);
    // el nivel al que podría avanzar con la xp actual
    int need_xp = level2xp(advance_level + 1) - xp;
    // la xp que necesitaría para avanzar al siguiente nivel
    int need_qp = (qp < QUESTMASTER->QueryTotalQuestPoints() ?
                   QUESTMASTER->QPointLevel(advance_level) - qp : 0);
    // los qp que necesitaría para avanzar al siguiente nivel
    int free_xp = xp - level2xp(level);
    // la xp que tiene para gastar

    if (need_qp > 0 && advance_level > level)
    // necesita qp para avanzar de nivel, aunque con la xp que tiene podría hacerlo
    {
        msg += "Con la XP actual podrías avanzar hasta el nivel " +
               advance_level + ". Sin embargo, te faltan " + need_qp + " QP " +
               "para avanzar a dicho nivel.\n";
        if (advance_level < level_w_qp)
        // puede avanzar de nivel
        {
            msg += "Con la XP y los QP actuales puedes avanzar hasta el nivel " + level_w_qp + ".\n";
        }
    }
    else if (advance_level > level)
    // puede avanzar de nivel.
    {
        msg += "Con la XP actual puedes avanzar hasta el nivel " +
               advance_level + ". Necesitas " + need_xp + " XP para avanzar al "
               "nivel " + (advance_level + 1) + ".\n";
    }
    else
    {
        msg += "Aún no puedes avanzar de nivel. Necesitas " + need_xp +
               " XP para avanzar hasta el nivel " + (level + 1) + ".\n";
    }
    if (free_xp && type == GREMIO)
    // si tiene xp para gastar y la modalidad es gremio, se notifica.
    {
        msg += "Tienes " + free_xp + " XP para gastar.\n";
    }
    return msg;
}

private int _calcular_gremio()
{
    object pl = TP;
    string gremio = pl->QueryGuild() || GC_NINGUNO;
    string msg;
    if (gremio == GC_NINGUNO)
    {
        return notify_fail(TIFLO(pl,"No perteneces a ningún gremio.\n"),
                           NOTIFY_NOT_VALID);
    }
    msg = "Tu nivel como " + gremio + " es " + pl->QueryGuildLevel() + ".\n";
    msg += _query_player_level_info(GREMIO);
    write(TIFLO(pl,msg));
    return 1;
}



private int _calcular_jugador()
{
    string msg = "Tu nivel como jugador es " + TP->QueryLevel() + ". ";
    msg += _query_player_level_info(JUGADOR);
    write(TIFLO(TP,msg));
    return 1;;
}

public int main(string str)
{
    if (!str || str != "jugador" && str != "gremio")
    {
        return notify_fail(TIFLO(TP, "Sintaxis: calcular gremio, o calcular "
                                     "jugador.\n"), NOTIFY_NOT_VALID);
    }
    if (str == "gremio") return _calcular_gremio();
    return _calcular_jugador();
}


create()
{
    seteuid(getuid());
}
