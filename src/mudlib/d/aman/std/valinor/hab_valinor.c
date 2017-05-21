/***
Fichero: hab_valinor.c
Autor: orome
Descripci�n: Habitaci�n est�ndard de valinor.
***/

#include "../path.h"
#include <bandos.h>

inherit ROOM;
create()
{
    ::create();
    SetLocate("Valmar");
    SetIntBando(P_BANDO_LUZ);
    SetIntNoise("No oyes nada anormal.\n");
    SetIntSmell("No hueles nada anormal.\n");
    SetIntBright(20);
    SetIndoors(0); // [Nyh] Esto pone el Server a NIGHTDAY
    SetClimateServer(SERVER);
}
