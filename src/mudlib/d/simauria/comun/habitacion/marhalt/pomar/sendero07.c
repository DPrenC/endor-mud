/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Hacia el noroeste "
  "continúa el camino hasta Enalel y hacia el sudeste está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("No hueles nada importante.\n");
  SetIntNoise("No escuchas nada importante.\n");
  
  AddExit("sudeste",POMARHAB"sendero06");
  AddExit("noroeste",POMARHAB"sendero08");
  SetLocate("el norte de Marhalt");
}
