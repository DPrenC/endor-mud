/*
DESCRIPCION : bosque37.c
*/

#include "path.h"

inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_TALEK("camino11"));
    AddExit("oeste",BOSQUE_TALEK("bosque36"));
    AddExit("suroeste",BOSQUE_TALEK("bosque31"));
}
