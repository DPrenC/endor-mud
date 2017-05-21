/*
DESCRIPCION  : barca al oeste del puerto
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/barca01.c
MODIFICACION : 14-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#define NOMBRE capitalize(TP->QueryName())
#include <moving.h>

#define GEN    (TP->QueryGenderEndString())

#include "./path.h"
inherit ROOM;

int muelle(){
  write("Desembarcas y subes al muelle.\n");
  say(NOMBRE+" desembarca y sube al muelle.\n",TP);
  tell_room(LIMBO("muelle00"),NOMBRE+" desembarca de la barca amarrada al oeste y sube al muelle.\n");
  TP->move(LIMBO("muelle00"),M_SILENT);
  return 1;
}

create() {
  ::create();
  SetIntShort("una barca de pesca");
  SetIntLong(
"Est�s a bordo de una de las barcas de pesca amarradas al muelle. La vela mayor "
"est� arriada, pero el foque no est� en el barco as� que supones que su due�o "
"debe estar reparando esta vela. La barca est� sujeta al muelle por un par de "
"cabos. Sujetos a los costados del barco hay un par de remos.\n");

AddDetail(({"puerto"}),
 "El puerto est� construido sobre las rocas de la costa de la bahia y de �l sale "
 "el muelle donde se amarran las barcas de pesca. El puerto continua tanto hacia "
 "el este como al oeste.\n");

AddDetail(({"muelle"}),
 "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
 "que se hunden en el mar apoy�ndose en su fondo. Est� barca amarrada al muelle "
 "por medio de un cabo.\n");

AddDetail(({"barcas"}),
 "Hay barcas de pescadores amarradas a ambos lados del muelle. Tu te hallas a "
 "bordo de una de ellas.\n");

AddDetail(({"barca"}),QueryIntLong());

SetIntNoise("Oyes a las olas chocar contra el muelle.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("este",SF(muelle));
}
