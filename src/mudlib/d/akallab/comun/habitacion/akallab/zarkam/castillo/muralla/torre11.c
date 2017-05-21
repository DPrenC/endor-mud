/*
DESCRIPCION : parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre11.c
MODIFICACION: 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=random(1)+1;
 nsalidas=3;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre13"));
 AddExit("abajo",Z_CASTILLO("muralla/torre15"));
 AddExit("oeste",Z_CASTILLO("muralla/almena07"));
 AddExit("este",Z_CASTILLO("muralla/almena05"));
 AddExit("sur",Z_CASTILLO("muralla/puente00"));
}
