/***
Fichero: _sal.c
Autor: kastwey@simauria
Descripción: Devuelve las salidas obvias de una habitación.
Creación: 19/11/2004
***/

#include <colours.h>

#define MSG_SPEAK "all_speak:"
#define TIFLO(x) (TP->QueryTiflo() ? MSG_SPEAK : "") + x


public int main(string str)
{
    object pl = TP;
    object env;
    string msg;
    int vision, pos;


    if (!pl) return 0;
    if (!(env = environment(pl)))
    {
        return notify_fail(TIFLO("No estás en ningún sitio.\n"));
    }
    if (vision = pl->CantSee())
    {
        return notify_fail(TIFLO((vision > 0 ? "Hay demasiada luz. " :
                                               "Está demasiado oscuro. ") +
                                 "No ves nada.\n"));
    }
    msg = tcfstr(env->Exits(pl->QueryBrief(),pl));
    if (!pl->QueryBrief() && (pos = strstr(msg,":")) != -1)
    {
        msg = msg[pos + 2..];
    }
    if (msg == "") msg = "No existe ninguna salida obvia.\n";
    if (msg[<1] != '\n') msg += "\n";
    msg = TC_EXIT + msg + TC_NORMAL;
    write(TIFLO(msg));
    return 1;
}