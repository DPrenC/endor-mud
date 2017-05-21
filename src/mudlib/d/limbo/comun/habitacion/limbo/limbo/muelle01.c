/*
DESCRIPCION  : Extremo del muelle del puerto
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/muelle01.c
MODIFICACION : 14-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el extremo del muelle del puerto");
  SetIntLong(
"Estás en el extremo del muelle del puerto. Junto a ti se halla un pescador "
"tratando de pescar con una caña, pero su cubo de pescado esta aún vacio... "
"Junto al muelle hay amarradas varias barcas de pesca.\n");

AddDetail(({"puerto"}),
 "El puerto está construido sobre las rocas de la costa de la bahia y de él sale "
 "el muelle donde se amarran las barcas de pesca. El puerto continua tanto hacia "
 "el este como al oeste.\n");

AddDetail(({"muelle"}),
 "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
 "que se hunden en el mar apoyandose en su fondo. Tiene una serie de amarres donde "
 "los pescadores pueden atar sus barcas.\n");

AddDetail(({"barca","barcas"}),
 "En este momento hay varias barcas amarradas en el muelle del puerto. Están "
 "hechas de madera y son estrechas pero alargadas, de tal forma que en ellas cabe "
 "uno o a lo sumo un par de pescadores y los aparejos de pesca.\n");

SetIntNoise("Oyes a las olas chocar contra el muelle.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("norte",LIMBO("muelle00"));
AddItem(PNJ("pescador"));
}
