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
  "continúa el camino hasta Enalel y hacia el este está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("No hueles nada importante.\n");
  SetIntNoise("No escuchas nada importante.\n");
  
  AddExit("este",POMARHAB"sendero03");
  AddExit("noroeste",POMARHAB"sendero05");
  SetLocate("el norte de Marhalt");
}
