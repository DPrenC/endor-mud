/****************************************************************************
Fichero: bosque017.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Orilla sur del r�o.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla sur del r�o Kandal");
    SetIntLong(QueryIntLong()+ " M�s hacia el oeste el r�o est� cruzado por un puente "
        "en un ancho camino.\n");
    AddDetail("camino", "Est� al oeste junto al  puente que atraviesa el r�o.\n");
    AddDetail("puente", "Cruza el r�o de norte a sur en el oeste junto al camino.\n");

    AddExit("este","./bosque018");
    AddExit("suroeste","./bosque024");
    AddExit("sur","./bosque025");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


