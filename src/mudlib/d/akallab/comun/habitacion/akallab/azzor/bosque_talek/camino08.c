/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino08.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("El Camino del Este describe aqu� una suave curva a medida "
        "que avanza por el interior del bosque de Talek. Observas que en "
        "esta zona el bosque es m�s denso y que por tanto la forma m�s f�cil "
        "de avanzar por �l es siguiendo el camino ya trazado. El camino "
        "contin�a hacia el sudeste y hacia el oeste.\n");
    AddExit("oeste",BOSQUE_TALEK("camino07"));
    AddExit("sudeste",BOSQUE_TALEK("camino09"));
    AddExit("norte",BOSQUE_TALEK("bosque38"));
    AddExit("sur",BOSQUE_TALEK("bosque28"));
}
