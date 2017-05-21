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
  "a ambos lados del camino hacia el sudeste. Al norte puedes ver un frondoso "
  "bosque. El camino continúa al noroeste hacia las montañas y hacia el sudeste "
  "está Enalel.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  AddDetail(({"manzano","manzanos"}),"Están hacia el sudeste.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Está "
  "hacia el sur.\n");
  AddDetail(({"bosque","frondoso bosque","bosque frondoso"}),"Está lejos "
  "hacia el norte.\n");

  AddExit("sudeste",POMARHAB"sendero29");
  AddExit("noroeste",POMARHAB"sendero31");
  SetLocate("el norte de Marhalt");
}
