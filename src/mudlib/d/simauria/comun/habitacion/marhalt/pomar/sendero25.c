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
  "lado este del camino. El camino contin�a al norte hacia las monta�as y "
  "hacia el sudeste lleva a la entrada a Enalel.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n en el lado este del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Est� "
  "al sur de aqu�.\n");
  
  AddExit("sudeste",POMARHAB"sendero24");
  AddExit("norte",POMARHAB"sendero26");
  SetLocate("el norte de Marhalt");
}
