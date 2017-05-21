/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();
SetLocate("el norte de Marhalt");
    SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras por el medio del camino del norte de Marhalt. Hacia "
  "el noroeste continua el camino hasta Enalel y hacia el este está Nandor.\n");
  SetIndoors(0);

  AddExit("este",POMARHAB"sendero01");
  AddExit("noroeste",POMARHAB"sendero03");
}
