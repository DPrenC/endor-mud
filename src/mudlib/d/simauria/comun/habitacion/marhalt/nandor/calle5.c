/****************************************************************************
Fichero: calle5.c
Autor: Ratwor
Fecha: 12/08/2007
Descripción: Una calle de Nandor.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetPreIntShort("cerca de");
    SetIntShort("la plaza");
    SetIntLong("Estás en una calle polvorienta como el resto pero más solitaria. Por "
        "aquí pasan sin duda más diligencias que personas, y por eso puedes ver algunas"
        " huellas de ruedas en el terreno.\n  Esta calle transcurre hacia el sur en"
        "dirección a las afueras de la aldea, pero hacia el norte te encontrarías en la "
        "plaza de Nandor.\n");

    SetIndoors(0);

    AddExit("norte","./calle42s");
    AddExit("noroeste","calle41s");
    AddExit("sur","./calle6");
    AddExit("este","./casas/casa5");
    AddDoor("este");
}

