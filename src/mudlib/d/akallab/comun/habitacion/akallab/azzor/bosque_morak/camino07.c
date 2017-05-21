/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino07.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntLong("El camino que atraviesa el bosque de Morak describe aquí una "
        "suave curva a medida que avanza por el interior del bosque. "
        "Observas que en esta zona el bosque es mas denso y que por tanto la "
        "forma más fácil de avanzar por él es siguiendo el camino ya trazado. "
        "El camino continúa hacia el este y hacia el sudeste.\n");
    AddExit("oeste",BOSQUE_MORAK("bosque10"));
    AddExit("norte",BOSQUE_MORAK("bosque09"));
    AddExit("suroeste",BOSQUE_MORAK("camino06"));
    AddExit("este",BOSQUE_MORAK("camino08"));
}
