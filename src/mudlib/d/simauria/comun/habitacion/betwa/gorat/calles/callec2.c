/****************************************************************************
Fichero: callec2.c
Autor: Ratwor
Fecha: 03/04/2008
Descripción: la calle del pescador
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetLocate("gorat");
    SetIntShort("la calle del pescador");
    SetIntLong("Estás en la entrada del pequeño pueblo pesquero de Gorat, en su calle "
    "más pequeña, la calle del pescador.\n Al suroeste continúa la calle, donde "
    "te adentrarás en este pequeño pueblo pesquero.\n Al nordeste tienes el camino que "
    "te sacará de la región de Betwa.\n");
    SetIndoors(0);

    AddExit("nordeste", CAMINOS "/simauria-gorat/camino30");
    AddExit("suroeste", "./callec1");
    AddItem( GORPNJ("guard"), REFRESH_DESTRUCT, 2);
}
