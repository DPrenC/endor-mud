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
    SetIntLong("Est�s en la parte sudeste del gran claro que se abre en este "
        "bosque. En �l, al noroeste de aqu�, se encuentra la caba�a de una "
        "conocida curandera. El camino del Este cruza el claro al oeste de "
        "aqu�.\n");
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
    AddExit("sur",BOSQUE_TALEK("bosque21"));
    AddExit("oeste",BOSQUE_TALEK("camino05"));
    AddExit("noroeste",BOSQUE_TALEK("claro01"));
    AddExit("norte",BOSQUE_TALEK("camino07"));
}
