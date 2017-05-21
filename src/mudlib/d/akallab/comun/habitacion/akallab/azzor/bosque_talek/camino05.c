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
        "abre en el bosque de Talek. El Camino del Este contin�a hacia el "
        "oeste y hacia el nordeste atravesando este claro. Al norte de aqu� "
        "se halla una peque�a caba�a de madera donde supones que debe vivir "
        "la conocida curandera del bosque de la que has o�do hablar.\n");
    AddDetail(({"claro"}),"Es una extensi�n de pradera sin �rboles en el "
        "medio del bosque. No deja de resultarte sorprendente que siendo "
        "este bosque m�s bien espeso haya aqu� un claro. Al noroeste del "
        "claro hay una peque�a caba�a de madera.\n");
    AddDetail(({"cabanya","cabanya de madera","caba�a","caba�a de madera"}),
        "Es una peque�a construcci�n que hay al noroeste del claro del "
        "bosque. Supones que en ella debe vivir una conocida curandera de la "
        "que has o�do hablar. Dicen que es capaz de preparar poderosas "
        "pociones y ung�entos con ingredientes que se encuentran en este "
        "bosque.\n");
    AddExit("este",BOSQUE_TALEK("claro00"));
    AddExit("oeste",BOSQUE_TALEK("camino04"));
    AddExit("sur",BOSQUE_TALEK("bosque20"));
    AddExit("norte",BOSQUE_TALEK("claro01"));
    AddExit("nordeste",BOSQUE_TALEK("camino07"));
}
