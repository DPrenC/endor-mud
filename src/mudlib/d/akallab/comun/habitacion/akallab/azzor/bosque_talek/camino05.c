/*
DESCRIPCION  : Claro en el bosque
FICHERO      : camino05.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Te encuentras en el extremo suroeste de un gran claro que se "
        "abre en el bosque de Talek. El Camino del Este continúa hacia el "
        "oeste y hacia el nordeste atravesando este claro. Al norte de aquí "
        "se halla una pequeña cabaña de madera donde supones que debe vivir "
        "la conocida curandera del bosque de la que has oído hablar.\n");
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
    AddExit("este",BOSQUE_TALEK("claro00"));
    AddExit("oeste",BOSQUE_TALEK("camino04"));
    AddExit("sur",BOSQUE_TALEK("bosque20"));
    AddExit("norte",BOSQUE_TALEK("claro01"));
    AddExit("nordeste",BOSQUE_TALEK("camino07"));
}
