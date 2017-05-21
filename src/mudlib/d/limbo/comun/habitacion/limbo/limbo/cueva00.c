/*
DESCRIPCION  : Cueva en el acantilado del este de la isla.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/cueva00.c
MODIFICACION : 19-01-97 [angor] Creacion.
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

int subirAcantilado(){
write("Con mucho cuidado, comienzas a ascender por las resbaladizas rocas del acantilado. Avanzas lentamente ante el peligro de resbalar y caer al mar. Tras un rato ascendiendo entre rocas, llegas al borde del acantilado.\n");

say(TP->QueryName()+" se acerca al borde de la cueva junto al acantilado y "
 "comienza a ascender con cuidado por él.\n",TP);

tell_room(LIMBO("camino11"),TP->QueryName()+" aparece por el borde del acantilado jadeando "
 "tras realizar una dificil ascensión por la húmeda pared de roca.\n");

TP->move(LIMBO("camino11"),M_SILENT);
TP->LookAfterMove();
return 1;
}

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("la entrada de una cueva");
  SetIntLong(
"La entrada de la cueva se encuentra en la pared del alto acantilado de la "
"costa este de la isla Limbo. A través de las rocas se puede ascender hasta la "
"cima del acantilado. La cueva es un estrecho corredor que se adentra en el "
"interior de la tierra.\n");

 AddDetail(({"acantilado","acantilados"}),
  "La isla acaba abruptamente en un alto acantilado rocoso a cuyos pies choca "
  "furiosamente el oleaje. Será mejor no aproximarse mucho, el suelo está "
  "húmedo y una caida podría ser fatal.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"torre de wizards","torre de Wizards","torre","Torre"}),
  "La torre de los Wizards es un edificio construido sobre una roca al "
  "este de la isla Limbo. En ella trabajan y se reunen los wizards, seres "
  "que ayudan a los dioses a crear este mundo, y además se encuentran una "
  "serie de servicios para resolver problemas, tales como la Justicia, que "
  "surjan con o entre los jugadores de Simauria.\n");

 SetIntNoise("Las olas rompen una y otra vez contra la base del acantilado.\n");
 SetIntSmell("Huele a mar.\n");
 SetLocate("isla Limbo");

AddExit("oeste",LIMBO("cueva01"));
AddExit("arriba",SF(subirAcantilado));

SetIndoors(0);

}

