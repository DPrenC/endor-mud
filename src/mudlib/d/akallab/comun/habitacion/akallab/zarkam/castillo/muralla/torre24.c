/*
DESCRIPCION : parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre24.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CASTILLO("muralla/torre_t1");

create() {
 guardias=random(2);
 nsalidas=3;
 ::create();
AddExit("arriba",Z_CASTILLO("muralla/torre26"));
 AddExit("abajo",Z_CASTILLO("muralla/torre25"));
 AddExit("norte",Z_CASTILLO("muralla/almena11"));
 AddExit("sur",Z_CASTILLO("muralla/almena12"));
 AddExit("este",Z_CASTILLO("muralla/puente01"));
}
