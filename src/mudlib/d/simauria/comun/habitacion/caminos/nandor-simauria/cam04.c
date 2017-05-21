/****************************************************************************
Fichero: cam04.c
Autor: Ratwor
Fecha: 21/01/2007
Descripci�n: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    SetIntLong(QueryIntLong()+" Al norte puedes ver un r�o que atraviesa el camino, y su"
        " correspondiente puente para cruzar por �l.\n");
    AddDetail("puente","Lo tienes al norte y atraviesa el r�o para que puedas seguir tu "
        "camino.\n");
    AddDetail(({"campos","campos de cultivo","cultivos"}), "Parece que son de ma�z.\n");
    AddDetail(({"rio","r�o","agua"}), "Es el r�o Kandal que viene desde el este, "
        "atravesando el bosque de Marhalt, y sigue su camino hacia la costa oeste de Simauria.\n");

    AddExit("sur","./cam05");
    AddExit("norte","./cam03");
    AddExit("sudeste", MARH("nandor/bosque/bosque024"));
    HideExit("sudeste",1);
}

