/****************************************************************************
Fichero: bosque017.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla sur del río.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla sur del río Kandal");
    SetIntLong(QueryIntLong()+ " Más hacia el oeste el río está cruzado por un puente "
        "en un ancho camino.\n");
    AddDetail("camino", "Está al oeste junto al  puente que atraviesa el río.\n");
    AddDetail("puente", "Cruza el río de norte a sur en el oeste junto al camino.\n");

    AddExit("este","./bosque018");
    AddExit("suroeste","./bosque024");
    AddExit("sur","./bosque025");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


