/****************************************************************************
Fichero: cam30.c
Autor: Ratwor
Fecha: 29/09/2007
Descripción: El camino de berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";
create() {
    ::create();
    SetIntLong(QueryIntLong()+" Parece que en este punto el camino se ensancha hacia el"
        " sur, donde se ve un puente a lo lejos. Y más al sur todavía,puedes divisar "
        "unas construcciones.\n");
    AddDetail(({"construcciones", "construcción", "construcion"}),
    " Deben de pertenecer al pueblo marítimo de Berat.\n");
    AddExit("norte","./cam29");
    AddExit("sur", SIMA("berat/camino1"));
}

