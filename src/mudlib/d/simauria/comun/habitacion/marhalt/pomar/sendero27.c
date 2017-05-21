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
  "lados del camino. El camino contin�a al noroeste hacia las monta�as y "
  "hacia el sudeste est� Enalel.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n a ambos lados del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Est� "
  "hacia el sur.\n");
  
  AddExit("sudeste",POMARHAB"sendero26");
  AddExit("noroeste",POMARHAB"sendero28");
  SetLocate("el norte de Marhalt");
}
