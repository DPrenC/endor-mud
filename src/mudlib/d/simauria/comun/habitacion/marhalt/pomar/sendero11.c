/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Cerca, hacia el norte, "
  "comienzas a ver manzanos. Hacia el noroeste continúa el camino hasta "
  "Enalel y hacia el sudeste está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Comienzas a percibir el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están más al norte.\n");
  
  AddExit("sudeste",POMARHAB"sendero10");
  AddExit("noroeste",POMARHAB"sendero12");
  SetLocate("el norte de Marhalt");
}
