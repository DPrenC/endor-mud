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
  "lado este del camino. En el lado oeste, la empalizada sigue bordeando el "
  "camino. El camino continúa al norte hacia las montañas y hacia el sudeste "
  "lleva a una entrada a Enalel.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están en el lado este del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Hay "
  "una entrada más al sur.\n");
  AddDetail(({"empalizada"}),"Es una alta empalizada construida para evitar "
  "ataques enemigos.\n");
  
  AddExit("sudeste",POMARHAB"sendero22");
  AddExit("norte",POMARHAB"sendero24");
  SetLocate("el norte de Marhalt");
}
