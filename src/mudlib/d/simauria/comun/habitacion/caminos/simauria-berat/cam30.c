/****************************************************************************
Fichero: cam30.c
Autor: Ratwor
Fecha: 29/09/2007
Descripci�n: El camino de berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";
create() {
    ::create();
    SetIntLong(QueryIntLong()+" Parece que en este punto el camino se ensancha hacia el"
        " sur, donde se ve un puente a lo lejos. Y m�s al sur todav�a,puedes divisar "
        "unas construcciones.\n");
    AddDetail(({"construcciones", "construcci�n", "construcion"}),
    " Deben de pertenecer al pueblo mar�timo de Berat.\n");
    AddExit("norte","./cam29");
    AddExit("sur", SIMA("berat/camino1"));
}

