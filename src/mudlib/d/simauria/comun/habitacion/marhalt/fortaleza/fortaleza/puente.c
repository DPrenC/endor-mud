/*
DESCRIPCION  : puente
FICHERO      : puente.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit SIM_ROOM;
create()
{
  ::create();
  SetIntShort("un puente sobre el foso");
  SetIntLong(W("Est�s en un puente levadizo sobre el foso, a la entrada de la "
  "famosa fortaleza de Cored. La madera que compone el puente es vieja, pero tambi�n "
  "parece incre�blemente resistente. El foso lleva bastante agua, y no puedes predecir "
  "que clase de criaturas habitan en �l.\n"));
  SetIntNoise("Oyes pisadas met�licas.\n");
  SetIntSmell("Huele bastante mal.\n");
  SetIndoors(0);
  AddDetail(({"bosque","bosque de la fortaleza"}),
     W("Es un bosque de mediano tama�o que se extiende en la parte norte "
       "de Nandor. Es un bosque no muy denso habitado principalmente por "
  	   "bandidos e indeseables de este tipo. Si no fuera por la chusma que "
  	   "lo habita, ser�a un lugar muy agradable.\n"));
  SetLocate("fortaleza de Cored");
  AddExit("sur",ROOMFS("senda1"));
  AddExit("norte",ROOMFF("torre01"));
  AddItem(PNJFF("sargento"));
  }
