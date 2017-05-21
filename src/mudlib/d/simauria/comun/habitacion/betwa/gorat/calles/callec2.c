/****************************************************************************
Fichero: callec2.c
Autor: Ratwor
Fecha: 03/04/2008
Descripci�n: la calle del pescador
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetLocate("gorat");
    SetIntShort("la calle del pescador");
    SetIntLong("Est�s en la entrada del peque�o pueblo pesquero de Gorat, en su calle "
    "m�s peque�a, la calle del pescador.\n Al suroeste contin�a la calle, donde "
    "te adentrar�s en este peque�o pueblo pesquero.\n Al nordeste tienes el camino que "
    "te sacar� de la regi�n de Betwa.\n");
    SetIndoors(0);

    AddExit("nordeste", CAMINOS "/simauria-gorat/camino30");
    AddExit("suroeste", "./callec1");
    AddItem( GORPNJ("guard"), REFRESH_DESTRUCT, 2);
}
