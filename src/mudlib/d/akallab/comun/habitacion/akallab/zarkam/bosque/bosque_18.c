/*
DESCRIPCION  : Bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_18.c
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

  AddDetail(({"arbol","arboles","copas"}),
    "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
    "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
    "o si esta nublado...\n");

  AddDetail(({"penyasco","penya"}),
    "Es increible, donde no hay un arbol hay una piedra. Grandes piedras, para "
    "ser mas exactos. Algunas demasiado grandes para sortearlas o escalarlas.\n");

  SetIntNoise("Todo esta en silencio, un silencio preocupante.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(10);

  AddExit("norte",Z_BOSQUE("bosque_28"));
  AddExit("sur",Z_BOSQUE("bosque_09"));
  AddExit("este",Z_BOSQUE("bosque_19"));
  AddExit("noroeste",Z_BOSQUE("bosque_27"));
  AddExit("sudeste",Z_BOSQUE("bosque_10"));
  AddExit("suroeste",Z_BOSQUE("bosque_08"));

  AddItem(PNJ("animal/oso"),REFRESH_DESTRUCT);
}
