/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino08.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntLong("El camino desciende ligeramente a medida que avanza a través "
        "del bosque en dirección este hasta alcanzar un puente. El puente "
        "debe cruzar el arroyo que oyes. El bosque en esta zona es más verde "
        "y frondoso. El camino continúa hacia el este y hacia el oeste.\n");
    AddDetail(({"puente"}),"Hacia el este, ves como el camino alcanza un "
        "puente.\n");
    AddExit("sur",BOSQUE_MORAK("bosque12"));
    AddExit("norte",BOSQUE_MORAK("bosque11"));
    AddExit("oeste",BOSQUE_MORAK("camino07"));
    AddExit("este",BOSQUE_MORAK("camino09"));
}
