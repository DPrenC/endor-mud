/*
DESCRIPCION : parte baja de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre18.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit Z_CASTILLO("muralla/torre_t2");

//los guardias PNJ no salen
int ir_ne(){
if (TP->QueryIsPlayer()) return TP->move(Z_CASTILLO("patio/patio15"),M_GO);
  return 1;
}

create() {
 guardias=0;
 nsalidas=1;
 ::create();
 AddExit("arriba",Z_CASTILLO("muralla/torre20"));
 AddExit("nordeste",SF(ir_ne));
}
