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
  "comienzas a ver lo que parecen manzanos. Hacia el noroeste contin�a el "
  "camino hasta Enalel y hacia el este est� Nandor.\n");
  SetIndoors(0);
  SetIntSmell("No hueles nada importante.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n m�s al norte.\n");
  
  AddExit("este",POMARHAB"sendero08");
  AddExit("noroeste",POMARHAB"sendero10");
  SetLocate("el norte de Marhalt");
}
