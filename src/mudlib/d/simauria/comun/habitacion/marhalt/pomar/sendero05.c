/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Hacia el oeste continúa "
  "el camino hasta Enalel y hacia el sudeste está Nandor.\n");
  SetIndoors(0);

  AddExit("sudeste",POMARHAB"sendero04");
  AddExit("oeste",POMARHAB"sendero06");
  SetLocate("el norte de Marhalt");
}
