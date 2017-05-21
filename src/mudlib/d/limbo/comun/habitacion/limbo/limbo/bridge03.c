/*
DESCRIPCION : Puente que conduce a la torre de los Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/puente00.c
MODIFICACION : 14-01-97 [angor] Creacion.
	       09/12/98 [g] modificacion para impedir a los jugatas entrar
	       		    a la torre.
*/

#include "./path.h"
#include <moving.h>

inherit LIMBO("bridge");


int saletorre(){

write ("Cruzas la niebla, y suspiras... dejando atras la torre.\n");

say(TP->QueryName()+" se introduce en la niebla y desaparece.\n");
tell_room(LIMBO("bridge02"),TP->QueryName()+
"aparece de entre la niebla.\n");

TP->move(LIMBO("bridge02"),M_SILENT);
call_out("msg",2);
return 1;
}

msg () {
   write("\n");
   write("Tras cruzar, la niebla te impide mirar a tu alrededor.\n");
   return 1;
}

create() {
  ::create();
  SetIntShort("el puente hacia la Torre de la Magia");
  SetIntLong(
"Miras hacia abajo desde el puente, y ves un enorme acantilado en cuyo fondo "
"las olas rompen contra las rocas produciendo un sonido apacible. La Torre de "
"la Magia se alza imponente ante tus pies. Hacia el Oeste, la niebla invade "
"la salida por el puente.\n");

AddDetail(({"niebla","espesa niebla","niebla espesa"}),
"La niebla se esparce por la superficie del puente, y no puedes ver la isla "
"debido a su espesor casi solido.\n");
AddDetail(({"puente","largo puente"}),
  "El puente conecta el borde del acantilado con la torre de los Wizards. Esta "
  "hecho de piedra y se apoya firmemente sobre varios altos arcos que se hunden "
  "apoyandose en el fondo del mar.\n");

 AddDetail(({"acantilado","acantilados"}),
  "La isla acaba abruptamente en un alto acantilado rocoso a cuyos pies choca "
  "furiosamente el oleaje. Sera mejor no aproximarse mucho, el suelo esta "
  "humedo y una caida podria ser fatal.\n");

   AddDetail(({"rocas","rocas del borde","rocas con plantas"}),
  "Unas pequenyas hierbas verdes crecen entre las rocas del borde del acantilado. "
  "Las plantas se agarran con fuerza entre las rocas para poder resistir las "
  "rachas de viento que las agitan con violencia.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"torre de wizards","torre de Wizards","torre","Torre"}),
  "La Torre de la Magia se alza ahora ante ti., y una extranya sensacion "
  "se apodera de tu mente Quiza podria ser peligroso...\n");

 SetIntNoise("Las olas rompen una y otra vez contra la base del acantilado.\n");
 SetIntSmell("Huele a mar.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

  AddExit("torre",LIMBO("../torrewiz/hall"));
  AddExit("oeste",SF(saletorre));

}

