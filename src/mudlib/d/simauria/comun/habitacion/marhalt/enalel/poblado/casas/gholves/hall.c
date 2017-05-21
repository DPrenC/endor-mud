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
  SetIntLong(W("Est�s en el hall de la entrada de la casa de la noble familia "
  "Gholves. Parece que est�n haciendo importantes reformas en la construcci�n "
  "y la casa se encuentra cerrada. Al sur est� la salida a la calle de las "
  "cosechas.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  
  AddExit("sur",ENALHAB"poblado/calles/calle15");
}