/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();
  
  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Poblado de Enalel");
  SetIntShort("la casa de la familia Gholves");
  SetIntLong(W("Estás en el hall de la entrada de la casa de la noble familia "
  "Gholves. Parece que están haciendo importantes reformas en la construcción "
  "y la casa se encuentra cerrada. Al sur está la salida a la calle de las "
  "cosechas.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  
  AddExit("sur",ENALHAB"poblado/calles/calle15");
}