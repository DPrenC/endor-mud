/*
DESCRIPCION  : Puerto del pueblo de la isla Limbo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/calle02.c
MODIFICACION : 13-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el puerto del pueblo");
  SetIntLong(
"La calle del pueblo alcanza aquí el puerto. Puedes observar ahora claramente la "
"bahia del sur de la isla donde se halla contruido el puerto. El puerto continua "
"hacia el oeste de aquí, mientras que al este se encuentra una tienda. El muelle "
"de madera del puerto avanza hacia el sur adentrandose en el mar. Hay varias "
"barcas de pesca amarradas a el y en su extremo un viejo pescador con una caña.\n");

AddDetail(({"puerto"}),
 "El puerto está construido sobre las rocas de la costa de la bahia y de él sale "
 "el muelle donde se amarran las barcas de pesca. El puerto continua tanto hacia "
 "el este como al oeste de aquí.\n");

AddDetail(({"muelle"}),
 "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
 "que se hunden en el mar apoyándose en su fondo. Tiene una serie de amarres donde "
 "los pescadores pueden atar sus barcas.\n");

AddDetail(({"pescador","viejo pescador"}),
 "Está sentado al final del muelle tratando de pescar, pero por sus gestos crees "
 "que no debe irle muy bien.\n");

AddDetail(({"barca","barcas"}),
 "En este momento hay varias barcas amarradas en el muelle del puerto. Están "
 "hechas de madera y son estrechas pero alargadas, de tal forma que en ellas cabe "
 "uno o a lo sumo un par de pescadores y los aparejos de pesca.\n");

SetIntNoise("Oyes a las olas chocar contra el puerto.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("sur",LIMBO("muelle00"));
AddExit("norte",LIMBO("calle03"));
AddExit("oeste",LIMBO("calle04"));
AddExit("este",LIMBO("tienda"));
}
