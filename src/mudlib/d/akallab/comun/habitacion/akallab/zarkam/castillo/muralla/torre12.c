/*
DESCRIPCION : parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre12.c
MODIFICACION: 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=random(1)+1;
 nsalidas=3;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre14"));
 AddExit("abajo",Z_CASTILLO("muralla/torre16"));
 AddExit("oeste",Z_CASTILLO("muralla/almena10"));
 AddExit("este",Z_CASTILLO("muralla/almena08"));
}
