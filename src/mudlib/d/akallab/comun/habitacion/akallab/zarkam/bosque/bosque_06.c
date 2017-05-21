/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
"El bosque es mas denso y cerrado por aqui, para avanzar tienes que evitar "
"e ir apartando cientos de ramas, asi como sortear algun que otro penyasco. "
"Las ramas de los arboles se entrecruzan sobre tu cabeza protegiendote de "
"las posibles inclemencias del tiempo, aunque, por otra parte, no contribuyen "
"a la iluminacion del bosque. "
"Parece que al este podrias pasar entre dos piedras o podrias ir al noroeste "
"que parece mas facil.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("este",Z_BOSQUE("bosque_07"));
  AddExit("noroeste",Z_BOSQUE("bosque_13"));
  AddDetail(({"arbol","arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado...\n");
  AddDetail(({"piedras","piedra","penyasco","penya"}),
  "Al este hay dos grandes piedras, aunque lo suficientemente separadas para "
  "que se pueda pasar entre ellas. Quien sabe lo que habra detras?\n");
  SetIntNoise("Oyes un rumor en la lejania...\n");
  SetIntSmell("El aire esta humedo.\n");
  SetLocate("bosque de Zarkam");
  switch (random(2)) {
  case 0:  AddItem(PNJ("animal/ardilla2"),REFRESH_DESTRUCT);
           break;
  case 1:  AddItem(PNJ("animal/ardilla"),REFRESH_DESTRUCT);
           break;
  }
  AddItem(QUEST+"amuleto/urraca", REFRESH_DESTRUCT);
}
