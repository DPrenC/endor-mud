/*
DESCRIPCION : parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre05.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=random(2);
 nsalidas=2;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre07"));
 AddExit("abajo",Z_CASTILLO("muralla/torre08"));
 AddExit("oeste",Z_CASTILLO("muralla/almena03"));
 AddExit("sur",Z_CASTILLO("muralla/almena01"));
}
