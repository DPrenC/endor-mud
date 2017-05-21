/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	camino del norte de Marhalt
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create(){
  ::create();

  SetIntShort("el camino del norte de Marhalt");
  SetIntLong("Te encuentras en el camino del norte de Marhalt. Puedes ver manzanos "
  "hacia el sudeste. Al norte puedes ver un frondoso bosque. Hacia el noroeste "
  "el camino entra en las montañas y hacia el sudeste está Enalel.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Están hacia el sudeste.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Está "
  "hacia el sur.\n");
  AddDetail(({"bosque","frondoso bosque","bosque frondoso"}),"Está lejos "
  "hacia el norte.\n");
  AddDetail(({"montaña","montanya","montañas","montanyas"}),"Están al noroeste.\n");

  AddExit("sudeste",POMARHAB"sendero30");
  AddExit("noroeste",POMARHAB"sendero32");
  SetLocate("el norte de Marhalt");
}
