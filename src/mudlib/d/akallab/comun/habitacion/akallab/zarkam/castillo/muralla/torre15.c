/*
DESCRIPCION : parte baja de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre15.c
MODIFICACION: 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit Z_CASTILLO("muralla/torre_t2");

//los guardias PNJ no salen
int ir_s(){
if (TP->QueryIsPlayer()) return TP->move(Z_CASTILLO("patio/patio06"),M_GO);
  return 1;
}

create() {
 guardias=1;
 nsalidas=1;
 ::create();
 AddExit("arriba",Z_CASTILLO("muralla/torre11"));
 AddExit("sur",SF(ir_s));
}
