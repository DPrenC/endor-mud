/****************************************************************************
Fichero: camino27.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();
    SetIntLong(QueryIntLong()+" Al suroeste empiezas a divisar unas construcciones que "
        "deben pertenecer a Gorat. Y al oeste se levanta un faro.\n");
    AddDetail(({"gorat", "Gorat"}), "Es el pueblo pesquero que se encuentra en la "
        "costa oeste de Simauria.\n");
    AddDetail("faro", "Es el faro de gorat que se levanta en la costa, ya parece "
        "estar cerca.\n");
    AddDetail(({"construcciones", "construcción", "construccion"}), "Son las casas del "
        "pequeño pueblo de Gorat.\n");
    AddExit("oeste", "./camino28");
    AddExit("nordeste", "./camino26");
}
