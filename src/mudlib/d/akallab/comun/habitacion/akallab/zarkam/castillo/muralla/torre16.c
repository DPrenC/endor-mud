/*
DESCRIPCION : parte baja de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/torre16.c
MODIFICACION: 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <moving.h>


inherit Z_CASTILLO("muralla/torre_t2");

//los guardias PNJ no salen
int ir_n(){
if (TP->QueryIsPlayer()) return TP->move(Z_CASTILLO("patio/patio09"),M_GO);
  return 1;
}

create() {
 guardias=random(1);
 nsalidas=1;
 ::create();
 AddExit("arriba",Z_CASTILLO("muralla/torre12"));
 AddExit("norte",SF(ir_n));
}
