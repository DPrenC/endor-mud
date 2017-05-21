/*
DESCRIPCION  : Claro en el bosque
FICHERO      : camino07.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Ante ti se abre un gran claro en el bosque de Talek. En el "
        "noroeste del mismo se encuentra una pequeña cabaña de madera, "
        "posiblemente el lugar donde vive una conocida curandera de la que "
        "has oído hablar. Un camino secundario parte hacia el norte desde el "
        "claro. El Camino del Este continúa hacia el este y hacia el "
        "suroeste atravesando el claro.\n");
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
    AddExit("este",BOSQUE_TALEK("camino08"));
    AddExit("sur",BOSQUE_TALEK("claro00"));
    AddExit("oeste",BOSQUE_TALEK("claro01"));
    AddExit("suroeste",BOSQUE_TALEK("camino05"));
    AddExit("norte",BOSQUE_TALEK("camino11"));
}
