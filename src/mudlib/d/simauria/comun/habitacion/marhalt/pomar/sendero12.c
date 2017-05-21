/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Al norte comienzas a "
  "ver los manzanos que dan nombre al camino. Hacia el norte continúa el "
  "camino hasta Enalel y hacia el sudeste está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están un poco más al norte.\n");
  
  AddExit("sudeste",POMARHAB"sendero11");
  AddExit("norte",POMARHAB"sendero13");
  SetLocate("el norte de Marhalt");
}
