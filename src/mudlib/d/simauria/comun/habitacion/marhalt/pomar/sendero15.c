/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Hay manzanos a ambos "
  "lados del camino. Hacia el norte continúa el camino hasta Enalel y hacia "
  "el sur está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están a ambos lados del camino.\n");
  
  AddExit("sur",POMARHAB"sendero14");
  AddExit("norte",POMARHAB"sendero16");
  SetLocate("el norte de Marhalt");
}
