/*
DESCRIPCION  : Bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : ??-??-?? [Elric@Simauria] Creacion
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
"a la iluminacion del bosque.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("oeste",Z_BOSQUE("bosque_03"));
  AddExit("nordeste",Z_BOSQUE("bosque_13"));
  AddExit("noroeste",Z_BOSQUE("bosque_11"));
  AddDetail(({"arbol","arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado...\n");
  AddDetail(({"penyasco","penya"}),
  "Es increible, donde no hay un arbol hay una piedra. Grandes piedras, para "
  "ser mas exactos. Algunas demasiado grandes para sortearlas o escalarlas.\n");
  SetIntNoise("Todo esta en silencio, un silencio preocupante.\n");
  SetIntSmell("Llenas tus pulmones de aire puro.\n");
  SetLocate("bosque de Zarkam");
}
