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
  "lados del camino y por encima de ellos puedes ver el pueblo de Enalel "
  "hacia el noroeste. Hacia el noroeste contin�a el camino hasta Enalel y "
  "hacia el sur est� Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n a ambos lados del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Est� "
  "al noroeste.\n");
  
  AddExit("sur",POMARHAB"sendero19");
  AddExit("noroeste",POMARHAB"sendero21");
  SetLocate("el norte de Marhalt");
}
