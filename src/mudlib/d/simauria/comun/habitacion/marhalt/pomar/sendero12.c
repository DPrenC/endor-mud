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
  "ver los manzanos que dan nombre al camino. Hacia el norte contin�a el "
  "camino hasta Enalel y hacia el sudeste est� Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n un poco m�s al norte.\n");
  
  AddExit("sudeste",POMARHAB"sendero11");
  AddExit("norte",POMARHAB"sendero13");
  SetLocate("el norte de Marhalt");
}
