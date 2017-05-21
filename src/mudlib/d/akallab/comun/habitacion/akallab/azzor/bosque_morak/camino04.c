/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino04.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("un claro en el camino a trav�s del bosque de Morak");
    SetIntLong("Hacia el noroeste de aqu� se abre un calvero en medio del "
        "bosque de Morak, dejando paso a una pequenya pradera. Del camino "
        "principal, en el que te encuentras, se desv�a un sendero hacia el "
        "noroeste, hacia la cantera que hay al pie de las monta�as y de la "
        "que has o�do hablar. El camino contin�a de este a oeste.\n");
    AddDetail(({"claro","calvero"}),"El calvero o claro, es una extensi�n de "
        "pradera sin �rboles en medio del bosque. El camino se divide en dos "
        "al oeste de aqu�.\n");
    AddExit("norte",BOSQUE_MORAK("bosque07"));
    AddExit("este",BOSQUE_MORAK("camino06"));
    AddExit("sur",BOSQUE_MORAK("bosque06"));
    AddExit("oeste",BOSQUE_MORAK("camino03"));
    AddExit("noroeste",BOSQUE_MORAK("camino10"));
}
