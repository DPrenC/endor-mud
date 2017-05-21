/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Hacia el noroeste el "
  "camino se adentra en las montañas y hacia el sudeste está Enalel.\n");
  SetIndoors(0);
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No escuchas nada importante.\n");

  AddExit("sudeste",POMARHAB"sendero33");
  AddExit("noroeste",POMARHAB"sendero35");
  SetLocate("el norte de Marhalt");
  if(d10()==1)
        AddItem(CAOSPNJ"ogro", REFRESH_DESTRUCT);
}
