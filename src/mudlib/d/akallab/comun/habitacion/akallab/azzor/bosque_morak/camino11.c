/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino11.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("el camino a la cantera, en el bosque de Morak");
    SetIntLong("El camino asciende lentamente a medida que avanza a trav�s "
        "del bosque hacia el pie de las monta�as al norte donde se encuentra "
        "la cantera. Notas en el suelo del camino algunas de las marcas que "
        "dejan las carretas con las que se transportan las pesadas piedras "
        "que se extraen de la cantera. El camino contin�a hacia el norte y "
        "hacia el sudeste.\n");
    AddDetail(({"marcas","huellas"}),"En el suelo de tierra del camino se "
        "pueden ver algunas de las huellas que a su paso por aqu� dejan las "
        "carretas cargadas con las pesadas piedras que se extraen de la "
        "cantera.\n");
    AddExit("este",BOSQUE_MORAK("bosque13"));
    AddExit("oeste",BOSQUE_MORAK("bosque14"));
    AddExit("norte",BOSQUE_MORAK("camino05"));
    AddExit("sudeste",BOSQUE_MORAK("camino10"));
}
