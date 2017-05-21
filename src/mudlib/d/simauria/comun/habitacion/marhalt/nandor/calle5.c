/****************************************************************************
Fichero: calle5.c
Autor: Ratwor
Fecha: 12/08/2007
Descripci�n: Una calle de Nandor.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetPreIntShort("cerca de");
    SetIntShort("la plaza");
    SetIntLong("Est�s en una calle polvorienta como el resto pero m�s solitaria. Por "
        "aqu� pasan sin duda m�s diligencias que personas, y por eso puedes ver algunas"
        " huellas de ruedas en el terreno.\n  Esta calle transcurre hacia el sur en"
        "direcci�n a las afueras de la aldea, pero hacia el norte te encontrar�as en la "
        "plaza de Nandor.\n");

    SetIndoors(0);

    AddExit("norte","./calle42s");
    AddExit("noroeste","calle41s");
    AddExit("sur","./calle6");
    AddExit("este","./casas/casa5");
    AddDoor("este");
}

