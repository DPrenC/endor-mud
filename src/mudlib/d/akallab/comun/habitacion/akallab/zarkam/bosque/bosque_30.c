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
"Al norte ves un gran arbol con una extranya construccion de madera en su copa, "
"parece una pequenya cabanya o una torreta de vigilancia.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("este",Z_BOSQUE("bosque_31"));
  AddExit("sur",Z_BOSQUE("bosque_20"));
  AddExit("oeste",Z_BOSQUE("bosque_29"));
  AddExit("nordeste",Z_BOSQUE("bosque_41"));
  AddExit("norte",Z_BOSQUE("bosque_40"));
  AddDetail(({"arbol","cabanya","construccion"}),
"De entre todos los arboles, el que mas te llama la atencion es uno que se "
"encuentra situado al norte de tu posicion y en el que, al parecer, hay una "
"construccion de madera en su copa.\n");
  AddDetail(({"arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado...\n");
  AddDetail(({"penyasco","penya"}),
  "Es increible, donde no hay un arbol hay una piedra. Grandes piedras, para "
  "ser mas exactos. Algunas demasiado grandes para sortearlas o escalarlas.\n");
  SetIntNoise("Oyes crujir las ramas bajo tus pies.\n");
  SetIntSmell("Ueles a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
}
