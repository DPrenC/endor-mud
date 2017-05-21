/****************************************************************************
Fichero: cam03.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");


create() {
    ::create();
    SetPreIntShort("sobre");
    SetIntShort("un puente");
    SetIntLong("Te encuentras sobre un puente de madera que atraviesa el río Kandal, "
    "el cual proviene del bosque de Nandor al este y se dirije hacia la "
        "costa oeste de Simauria.\n");
    AddDetail("puente","Es el puente de madera que atraviesa el río por el camino de "
        "Nandor a Ishtria. Se encuentra ya algo desgastado por el gran uso que se le"
        " da, teniendo en cuenta que por él pasan diariamente multitud de transeuntes"
        " a pié, en caballos, carros y diligencias.\n");
    AddDetail(({"rio","río","agua"}), "Es el río Kandal que proviene del bosque de "
        "Marhalt que se encuentra al este.\n");
    AddExit("sur","./cam04");
    AddExit("norte", "./cam02");

    AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT, d2());
}

