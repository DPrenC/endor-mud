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
  SetIntLong(W("Est�s en la escalinata de ascenso hasta el altar de la diosa "
  "Deiene. Las escaleras est�n talladas en la propia roca y van ascendiendo "
  "rodeandola. Las escaleras ascienden por el nordeste y descienden por el oeste.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"escalera","escaleras","pelda�o","pelda�os","peldanyo","peldanyos"}),
  W("Los pelda�os est�n tallados en la roca y parecen muy muy gastados, ser� mejor "
  "tener cuidado al pasar por aqu�."));
  AddExit("oeste",ENALHAB"templo/escaleras1");
  AddExit("nordeste",ENALHAB"templo/escaleras3");
}