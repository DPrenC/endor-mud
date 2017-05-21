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
  "lado este del camino. La empalizada de Enalel gira m�s hacia el oeste "
  "bordeando el gran manzanal del poblado de Enalel. El camino contin�a al "
  "noroeste hacia las monta�as y hacia el sur lleva a una entrada a Enalel.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n en el lado este del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Es "
  "un rico poblado dedicado al cultivo de las manzanas.\n");
  AddDetail(({"empalizada"}),"Es una alta empalizada construida para evitar "
  "ataques enemigos.\n");
  
  AddExit("sur",POMARHAB"sendero23");
  AddExit("noroeste",POMARHAB"sendero25");
  SetLocate("el norte de Marhalt");
}
