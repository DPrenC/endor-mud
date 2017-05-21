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
  SetLocate("Casa Benjus");
  SetIntShort("el pasillo");
  SetIntLong(W("Estás en un pasillo de paredes de madera. El pasillo continúa "
  "hacia el este y el oeste.\n"));
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
  AddDetail(({"pared","paredes","pared de madera","paredes de madera"}),W("Las "
  "paredes de madera crean un ambiente confortable en este largo pasillo.\n"));

  AddExit("este",ENALHAB"poblado/casas/benjus/pasillo2");
  AddExit("oeste",ENALHAB"poblado/casas/benjus/pasillo4");
}
