/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino03.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("El Camino del Este describe aquí una suave curva a medida "
        "que avanza por el interior del bosque de Talek. Observas que en "
        "esta zona el bosque es mas denso y que por tanto la forma mas fácil "
        "de avanzar por él es siguiendo el camino ya trazado. El camino "
        "continúa hacia el sudeste y hacia el oeste.\n");
    AddExit("oeste",BOSQUE_TALEK("camino02"));
    AddExit("sudeste",BOSQUE_TALEK("camino04"));
    AddExit("norte",BOSQUE_TALEK("bosque35"));
    AddExit("sur",BOSQUE_TALEK("bosque27"));
}
