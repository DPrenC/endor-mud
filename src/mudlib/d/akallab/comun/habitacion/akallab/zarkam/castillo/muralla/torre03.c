/*
DESCRIPCION : parte media una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/torre03.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=0;
 nsalidas=2;
 ::create();
 AddExit("arriba",Z_CASTILLO("muralla/torre02"));
 AddExit("abajo",Z_CASTILLO("muralla/torre04"));
 AddExit("norte",Z_CASTILLO("muralla/almena00"));
 AddExit("sur",Z_CASTILLO("muralla/almena02"));
}
