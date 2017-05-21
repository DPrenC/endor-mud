/*
DESCRIPCION : parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre19.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=random(2);
 nsalidas=2;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre21"));
 AddExit("abajo",Z_CASTILLO("muralla/torre17"));
 AddExit("este",Z_CASTILLO("muralla/almena09"));
 AddExit("sur",Z_CASTILLO("muralla/almena11"));
}
