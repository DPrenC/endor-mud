/****************************************************************************
Fichero: _gxp.c
Autor: kastwey@simauria
Descripción: Devuelve la xp de gremio.
Creación: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"
#define TIFLO(x) (TP->QueryTiflo() ? MSG_SPEAK : "") + x

#include <guild.h>



public int main()
{
    if (TP->QueryGuild() == GC_NINGUNO)
    {
        return notify_fail(TIFLO("No perteneces a ningún gremio.\n"));
    }
    write(TIFLO(TP->QueryGuildXP()+ "\n"));
    return 1;
}

