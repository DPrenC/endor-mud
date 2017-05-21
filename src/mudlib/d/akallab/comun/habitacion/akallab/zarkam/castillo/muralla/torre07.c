/*
DESCRIPCION : parte de arriba de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre07.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t0");

create() {
 guardias=1;
 ::create();
 AddExit("abajo",Z_CASTILLO("muralla/torre05"));
}
