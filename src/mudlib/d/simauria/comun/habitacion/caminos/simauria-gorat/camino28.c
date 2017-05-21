/****************************************************************************
Fichero: camino28.c
Autor: Ratwor
Fecha: 12/11/2006
Descripci�n: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();
    SetIntLong(QueryIntLong()+" Al sur ya se ve el pueblo de Gorat, y el faro cada vez "
        "est� m�s cerca hacia el oeste.\n");
    AddDetail(({"gorat", "Gorat"}), "Es el pueblo pesquero que se encuentra en la "
        "costa oeste de Simauria.\n");
    AddDetail("faro", "Es el faro de gorat que se levanta en la costa, ya parece "
        "estar cerca.\n");
    AddDetail(({"construcciones", "construcci�n", "construccion"}), "Son las casas del "
        "peque�o pueblo de Gorat.\n");


    AddExit("sur", "./camino29");
    AddExit("este", "./camino27");
}
