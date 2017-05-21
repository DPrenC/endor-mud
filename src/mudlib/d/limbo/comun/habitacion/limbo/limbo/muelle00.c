/*
DESCRIPCION  : Muelle del puerto
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/muelle00.c
MODIFICACION : 14-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include <moving.h>
#include "./path.h"

#define NOMBRE capitalize(TP->QueryName())
#define GEN    (TP->QueryGenderEndString())

inherit ROOM;

int barca_este(){
  write("Subes a bordo de la barca de pesca que hay amarrada al este del muelle.\n");
  say(NOMBRE+" sube a bordo de barca de pesca que hay amarrada al este del muelle.\n",TP);
  tell_room(LIMBO("barca00"),NOMBRE+" sube a bordo de esta barca desde el muelle.\n");
  TP->move(LIMBO("barca00"),M_SILENT);
  return 1;
}

int barca_oeste(){
  write("Subes a bordo de la barca de pesca que hay amarrada al oeste del muelle.\n");
  say(NOMBRE+" sube a bordo de barca de pesca que hay amarrada al oeste del muelle.\n",TP);
  tell_room(LIMBO("barca01"),NOMBRE+" sube a bordo de esta barca desde el muelle.\n");
  TP->move(LIMBO("barca01"),M_SILENT);
  return 1;
}

create() {
  ::create();
  SetIntShort("el muelle del puerto");
  SetIntLong(
"Te hallas en medio del muelle de madera del puerto. El muelle parte del puerto "
"y va adentrandose en el mar. En su extremo, se encuentra un viejo pescador con "
"una canya. Hacia el norte observas el pequenyo pueblo de pescadores cuya calle "
"principal desemboca en el puerto. A cada lado del muelle está amarrada una barca "
"de pesca con los correspondientes aparejos.\n");

AddDetail(({"puerto"}),
 "El puerto está construido sobre las rocas de la costa de la bahia y de él sale "
 "el muelle donde se amarran las barcas de pesca. El puerto continua tanto hacia "
 "el este como al oeste.\n");

AddDetail(({"muelle"}),
 "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
 "que se hunden en el mar apoyándose en su fondo. Tiene una serie de amarres donde "
 "los pescadores pueden atar sus barcas.\n");

AddDetail(({"pescador","viejo pescador"}),
 "Está sentado al final del muelle tratando de pescar, pero por sus gestos crees "
 "que no debe irle muy bien.\n");

AddDetail(({"barca","barcas"}),
 "A ambos lados del muelle a la altura a la que te encuentras se halla una barca "
 "de pesca. Están hechas de madera y son estrechas pero alargadas, de tal forma "
 "que en ellas cabe uno o a lo sumo un par de pescadores y los aparejos de pesca.\n");

SetIntNoise("Oyes a las olas chocar contra el muelle.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("sur",LIMBO("muelle01"));
AddExit("norte",LIMBO("calle02"));
AddExit("este",SF(barca_este));
AddExit("oeste",SF(barca_oeste));
}
