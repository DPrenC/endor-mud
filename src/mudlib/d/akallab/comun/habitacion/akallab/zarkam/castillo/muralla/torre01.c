/*
DESCRIPCION : parte media una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/torre01.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=0;
 nsalidas=2;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre00"));
 AddExit("abajo",Z_CASTILLO("muralla/torre23"));
 AddExit("norte",Z_CASTILLO("muralla/almena01"));
 AddExit("sur",Z_CASTILLO("muralla/almena00"));
}
