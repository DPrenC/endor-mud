/*
DESCRIPCION : almenas de la muralla del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/almena13.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/almena");

create() {
 guardias=1;
 ::create();
AddExit("norte",Z_CASTILLO("muralla/almena12"));
 AddExit("sur",Z_CASTILLO("muralla/almena14"));
}
