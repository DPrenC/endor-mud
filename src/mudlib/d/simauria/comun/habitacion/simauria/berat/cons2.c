/****************************************************************************
Fichero: cons2.c
Autor: Ratwor
Fecha: 15/11/2007
Descripci�n: Camino cortado.
****************************************************************************/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un camino en construcci�n");
    SetIntLong("Est�s en un camino que sale de Berat. El camino est� en "
    "construcci�n, y parece que todav�a est� poco avanzado, no va a ninguna parte.\n "
    " Por ahora, lo mejor que puedes hacer es volver atr�s.\n");
    SetIndoors(0);
    AddExit("oeste","./puente2");
}
