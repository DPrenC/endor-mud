/*
DESCRIPCION : almenas de la muralla del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/almena07.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/almena");

create() {
 guardias=1;
 ::create();
AddExit("este",Z_CASTILLO("muralla/torre11"));
 AddExit("oeste",Z_CASTILLO("muralla/almena09"));
}
