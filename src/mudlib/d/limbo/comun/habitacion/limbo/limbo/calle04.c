/*
DESCRIPCION  : Puerto del pueblo de la isla Limbo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/calle04.c
MODIFICACION : 15-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el puerto del pueblo");
  SetIntLong(
"Te encuentras en el extremo oeste del puerto. Al este de aqu� se halla el muelle "
"del puerto donde amarran las barcas de pesca y el poblado de pescadores. De aqu� "
"sale un camino que asciende entre rocas hasta el faro que observas al suroeste.\n");

AddDetail(({"puerto"}),
 "El puerto est� construido sobre las rocas de la costa de la bahia y de �l sale "
 "el muelle donde se amarran las barcas de pesca. Te hallas en su extremo oeste.\n");

AddDetail(({"muelle"}),
 "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
 "que se hunden en el mar apoy�ndose en su fondo. Tiene una serie de amarres donde "
 "los pescadores pueden atar sus barcas.\n");

AddDetail(({"barca","barcas"}),"En este momento hay varias barcas amarradas en el muelle del puerto.\n");

SetIntNoise("Oyes a las olas chocar contra el puerto.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("este",LIMBO("calle02"));
AddExit("suroeste",LIMBO("faro"));
}
