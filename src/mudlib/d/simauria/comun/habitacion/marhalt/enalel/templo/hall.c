/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Templo de Deiene
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Poblado de Enalel");
  SetIntShort("la entrada del templo de Deiene");
  SetIntLong(W("Estás en la entrada del templo de la diosa Deiene. Es un enorme "
  "portal construido con la flora y la piedra que aquí se encontraban. Parece "
  "que la mano del hombre no ha tocado nada en la construcción. El templo, "
  "situado al norte de aquí, parece excavado dentro de una enorme roca. Hacia "
  "el sur está la salida hacia la calle de las cosechas.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddExit("norte",ENALHAB"templo/escaleras1");
  AddExit("sur",ENALHAB"poblado/calles/calle18");
}
