/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino14.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("En este lugar el camino que recorre el bosque describe una "
        "suave curva de sudeste a oeste. Observas que en esta zona el bosque "
        "es más denso y que por tanto la forma más fácil de avanzar por "
        "él es siguiendo el camino ya trazado. Oyes a lo lejos el ruido de "
        "un río.\n");
    AddExit("sudeste",BOSQUE_TALEK("camino13"));
    AddExit("este",BOSQUE_TALEK("bosque53"));
    AddExit("sur",BOSQUE_TALEK("bosque49"));
    AddExit("oeste",BOSQUE_TALEK("camino15"));
}
