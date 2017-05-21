/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Lejos, hacia el norte, "
  "comienzas a ver lo que parecen manzanos. Hacia el oeste continúa el camino "
  "hasta Enalel y hacia el sudeste está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("No hueles nada importante.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están más al norte.\n");
  
  AddExit("sudeste",POMARHAB"sendero07");
  AddExit("oeste",POMARHAB"sendero09");
  SetLocate("el norte de Marhalt");
}
