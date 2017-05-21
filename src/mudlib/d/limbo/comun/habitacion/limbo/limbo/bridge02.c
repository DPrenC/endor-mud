/*
DESCRIPCION : Puente que conduce a la torre de los Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/puente00.c
MODIFICACION : 14-01-97 [angor] Creacion.
               14-10-99 [woo] Ahora solo pueden entrar los > learner.
*/

#include "./path.h"
#include <wizlevels.h>
#include <moving.h>

inherit LIMBO("bridge");


int entratorre(){

/*
if (!IS_LEARNER(TP))
  return notify_fail("Una extraña fuerza te impide entrar...\n"),0;
*/

write ("Cruzas la niebla del puente, y una sensación extraña recorre tu "
"médula produciéndote un escalofrio por todo el cuerpo.\n")
;

say(TP->QueryName()+" se introduce en la niebla y desaparece.\n");

tell_room(LIMBO("bridge03"),TP->QueryName()+" aparece de entre la "
"niebla.\n");

TP->move(LIMBO("bridge03"),M_SILENT);
call_out("msj",2);
return 1;
}

msj() {
   write("\nLa niebla te impide ver que tienes a tu alrededor.\n");
   return 1;
}
create() {
  ::create();
  SetIntShort("el puente hacia la Torre de la Magia");
  SetIntLong(
"Miras hacia abajo desde el puente, y ves un enorme acantilado en cuyo fondo "
"se ven las olas rompientes. Una extraña sensación recorre tu cuerpo a medida "
"que te acercas a la torre, custodiada por una espesa niebla.\n");

AddDetail(({"niebla","espesa niebla","niebla espesa"}),
"Es una fría y espesa niebla que custodia la torre.\n");
AddDetail(({"puente","largo puente"}),
  "El puente conecta el borde del acantilado con la torre de los Wizards. Está "
  "hecho de piedra y se apoya firmemente sobre varios altos arcos que se hunden "
  "apoyándose en el fondo del mar.\n");

 AddDetail(({"acantilado","acantilados"}),
  "La isla acaba abruptamente en un alto acantilado rocoso a cuyos pies choca "
  "furiosamente el oleaje. Será mejor no aproximarse mucho, el suelo está "
  "húmedo y una caida podria ser fatal.\n");

   AddDetail(({"rocas","rocas del borde","rocas con plantas"}),
  "Unas pequeñas hierbas verdes crecen entre las rocas del borde del acantilado. "
  "Las plantas se agarran con fuerza entre las rocas para poder resistir las "
  "rachas de viento que las agitan con violencia.\n");

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
 SetIndoors(0);

 AddExit("oeste",LIMBO("bridge01"));
 AddExit("este",SF(entratorre));

}

