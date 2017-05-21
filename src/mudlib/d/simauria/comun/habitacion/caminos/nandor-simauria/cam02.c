/****************************************************************************
Fichero: cam02.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");


create() {
    ::create();
    SetIntLong("Vas caminando por el camino que une la capital Ishtria con la villa de"
        " Nandor, entre el bosque del este y los campos de cultivo del oeste. Al sur"
        " se dislumbra un puente que cruza el río que atraviesa el bosque.\n");
    AddDetail("puente","Lo tienes al sur y atraviesa el río para que puedas seguir tu "
        "camino.\n");
    AddDetail(({"campos","campos de cultivo","cultivos"}), "Parece que son de maíz.\n");
    AddDetail(({"rio","río","agua"}), "Es el río que proviene del bosque de Nandor del "
        "este.\n");
    AddExit("sur","./cam03");
    AddExit("norte","./cam01");
    AddExit("este", MARH("nandor/bosque/bosque007"));
    HideExit("este",1);
}
