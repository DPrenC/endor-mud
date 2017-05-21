/*
DESCRIPCION  : Claro en el bosque
FICHERO      : claro00.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntShort("un claro en el bosque");
    SetIntLong("Estás en la parte sudeste del gran claro que se abre en este "
        "bosque. En él, al noroeste de aquí, se encuentra la cabaña de una "
        "conocida curandera. El camino del Este cruza el claro al oeste de "
        "aquí.\n");
    AddDetail(({"claro"}),"Es una extensión de pradera sin árboles en el "
        "medio del bosque. No deja de resultarte sorprendente que siendo "
        "este bosque más bien espeso haya aquí un claro. Al noroeste del "
        "claro hay una pequeña cabaña de madera.\n");
    AddDetail(({"cabanya","cabanya de madera","cabaña","cabaña de madera"}),
        "Es una pequeña construcción que hay al noroeste del claro del "
        "bosque. Supones que en ella debe vivir una conocida curandera de la "
        "que has oído hablar. Dicen que es capaz de preparar poderosas "
        "pociones y ungüentos con ingredientes que se encuentran en este "
        "bosque.\n");
    AddExit("sur",BOSQUE_TALEK("bosque21"));
    AddExit("oeste",BOSQUE_TALEK("camino05"));
    AddExit("noroeste",BOSQUE_TALEK("claro01"));
    AddExit("norte",BOSQUE_TALEK("camino07"));
}
