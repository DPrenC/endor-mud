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
  "lado este del camino. La puerta del poblado de Enalel est� al oeste. El "
  "camino contin�a al norte hacia las monta�as y hacia el sudeste est� Nandor.\n");
  SetIndoors(0);
  SetIntSmell("Percibes el aroma de los manzanos.\n");
  SetIntNoise("No escuchas nada importante.\n");
  AddDetail(({"manzano","manzanos"}),"Est�n en el lado este del camino.\n");
  AddDetail(({"Enalel","enalel","pueblo de Enalel","pueblo de enalel"}),"Es "
  "un r�stico pero adinerado poblado de humanos y medioelfos.\n");
  
  AddExit("sudeste",POMARHAB"sendero20");
  AddExit("norte",POMARHAB"sendero22");
  AddExit("oeste",ENALHAB"poblado/calles/calle01");
  SetLocate("el norte de Marhalt");
}
