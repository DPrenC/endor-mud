/*
DESCRIPCION : almenas de la muralla del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/almena10.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/almena");

create() {
 guardias=0;
 ::create();
AddExit("oeste",Z_CASTILLO("muralla/torre20"));
 AddExit("este",Z_CASTILLO("muralla/torre12"));
}
