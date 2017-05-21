/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Hay manzanos en el "
  "lado este del camino. La puerta del poblado de Enalel está al oeste. El "
  "camino continúa al norte hacia las montañas y hacia el sudeste está Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están en el lado este del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Es "
  "un rústico pero adinerado poblado de humanos y medioelfos.\n");
  
  AddExit("sudeste",POMARHAB"sendero20");
  AddExit("norte",POMARHAB"sendero22");
  AddExit("oeste",ENALHAB"poblado/calles/calle01");
  SetLocate("el norte de Marhalt");
}
