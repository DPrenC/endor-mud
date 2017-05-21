/*
DESCRIPCION  : Boveda del Templo de Asthar
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/asthar_boveda.c
MODIFICACION : 07-02-98 [Angor@Simauria] Creacion.
               30-09-98 [Angor@Simauria] Varias modificaciones
               10-10-99 [Woo] Otras tantas...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>
inherit ROOM;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

int bajarTemplo(){
write(
  "A medida que desciendes lentamente comienzas a atravesar la esfera de luz y el "
  "interior del templo se hace cada vez más visible.\n");
say(NOMBRE+" se aleja descendiendo lentamente hacia el interior del templo.\n",TP);
tell_room(TEMPLO("templo04"),"El espíritu de "+NOMBRE+" baja desde la bóveda del templo.\n");
TP->move(TEMPLO("templo04"),M_GO);
return 1;
}


create() {
  ::create();
  SetIntShort("la bóveda del templo de Asthar");
  SetIntLong(
"Tu cuerpo inmaterial se encuentra flotando libre en el aire en el interior de "
"una especie de esfera de luz blanca y cálida que te impide distinguir "
"claramente saber que hay más allá. Oyes una voz grave y amable en tu interior "
"que te felicita por haber llegado a este mundo de Simauria. Esta misma voz te "
"indica que te encuentras en el interior de la bóveda del templo de Asthar en "
"Limbo, la isla de los Dioses, y que deberias bajar al templo para encarnarte "
"en un cuerpo mortal antes de poder vagar libremente por este mundo.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
 "a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
 "primeros pasos para vivir en este mundo de Simauria.\n");

AddDetail(({"boveda","esfera","luz"}),
 "Es una esfera espaciosa pero no puedes concretar más, ya que la luz que emana "
 "sus blancas paredes crea un ambiente un tanto irreal, como en un sueño.\n");

AddDetail(({"voz"}),"¿Cómo quieres ver un sonido?.\n");

SetIntNoise("Solo hay silencio.\n");
SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);
AddExit("abajo",SF(bajarTemplo));
SetSafe(1);
}
