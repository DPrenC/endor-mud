/****************************************************************************
Fichero: cons2.c
Autor: Ratwor
Fecha: 15/11/2007
Descripción: Camino cortado.
****************************************************************************/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un camino en construcción");
    SetIntLong("Estás en un camino que sale de Berat. El camino está en "
    "construcción, y parece que todavía está poco avanzado, no va a ninguna parte.\n "
    " Por ahora, lo mejor que puedes hacer es volver atrás.\n");
    SetIndoors(0);
    AddExit("oeste","./puente2");
}
