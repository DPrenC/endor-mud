/*
DESCRIPCION : almenas de la muralla del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/almena08.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/almena");

create() {
 guardias=1;
 ::create();
AddExit("oeste",Z_CASTILLO("muralla/torre12"));
 AddExit("este",Z_CASTILLO("muralla/almena06"));
}
