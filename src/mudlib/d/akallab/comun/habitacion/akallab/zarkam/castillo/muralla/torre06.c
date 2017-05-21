/*
DESCRIPCION : parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre06.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=random(1);
 nsalidas=2;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre09"));
 AddExit("abajo",Z_CASTILLO("muralla/torre10"));
 AddExit("oeste",Z_CASTILLO("muralla/almena04"));
 AddExit("norte",Z_CASTILLO("muralla/almena02"));
}
