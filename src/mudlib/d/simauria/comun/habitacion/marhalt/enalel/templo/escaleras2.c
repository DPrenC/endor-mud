/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Templo de Deiene
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("Templo de Deiene");
  SetIntShort("las escaleras del ascenso");
  SetIntLong(W("Estás en la escalinata de ascenso hasta el altar de la diosa "
  "Deiene. Las escaleras están talladas en la propia roca y van ascendiendo "
  "rodeandola. Las escaleras ascienden por el nordeste y descienden por el oeste.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"escalera","escaleras","peldaño","peldaños","peldanyo","peldanyos"}),
  W("Los peldaños están tallados en la roca y parecen muy muy gastados, será mejor "
  "tener cuidado al pasar por aquí."));
  AddExit("oeste",ENALHAB"templo/escaleras1");
  AddExit("nordeste",ENALHAB"templo/escaleras3");
}