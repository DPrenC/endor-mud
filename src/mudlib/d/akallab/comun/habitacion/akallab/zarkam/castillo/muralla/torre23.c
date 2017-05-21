/*
DESCRIPCION : parte baja de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre23.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit Z_CASTILLO("muralla/torre_t2");

//los guardias PNJ no salen
int ir_o(){
if (TP->QueryIsPlayer()) return TP->move(Z_CASTILLO("patio/guardia"),M_GO);
  return 1;
}

create() {
 guardias=0;
 nsalidas=1;
 ::create();
 AddExit("arriba",Z_CASTILLO("muralla/torre01"));
 AddExit("oeste",SF(ir_o));
}
