/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Un derrumbamiento "
  "de rocas ha cerrado el paso hacia el noroeste. Hacia el nordeste lleva "
  "a una enorme caverna y hacia el sudeste está Enalel.\n");
  SetIndoors(0);
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No escuchas nada importante.\n");

  AddDetail(({"derrumbamiento","rocas","derrumbamiento de rocas"}),"El "
  "derrumbamiento ha cerrado el paso hacia el noroeste, de momento.\n");

  AddExit("nordeste",POMARCAOS);
  AddExit("sudeste",POMARHAB"sendero34");
  SetLocate("el norte de Marhalt");
  if(d10()==1)
        AddItem(CAOSPNJ"ogro", REFRESH_DESTRUCT,d2());
}
