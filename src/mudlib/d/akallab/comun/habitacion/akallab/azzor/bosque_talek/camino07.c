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
        "noroeste del mismo se encuentra una peque�a caba�a de madera, "
        "posiblemente el lugar donde vive una conocida curandera de la que "
        "has o�do hablar. Un camino secundario parte hacia el norte desde el "
        "claro. El Camino del Este contin�a hacia el este y hacia el "
        "suroeste atravesando el claro.\n");
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
    AddExit("este",BOSQUE_TALEK("camino08"));
    AddExit("sur",BOSQUE_TALEK("claro00"));
    AddExit("oeste",BOSQUE_TALEK("claro01"));
    AddExit("suroeste",BOSQUE_TALEK("camino05"));
    AddExit("norte",BOSQUE_TALEK("camino11"));
}
