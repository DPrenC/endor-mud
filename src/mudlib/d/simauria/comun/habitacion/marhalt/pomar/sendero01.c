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
  SetIntLong("Te encuentras en el medio del camino del norte de Marhalt. Hacia el "
  "oeste continua el camino hasta Enalel y hacia el sudeste está Nandor.\n");
  SetIndoors(0);

    AddExit("sudeste", CAMINOS "/norte_marhalt/camino50");
    AddExit("oeste",POMARHAB"sendero02");
}
