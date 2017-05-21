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
"El paisaje comienza a ser demasiado monotono, arboles y mas arboles, hojas, "
"ramas, piedras... En este bosque es realmente facil perder la orientacion. "
"Pero hay algo especial en este lugar, algo que no tiene sentido, que se haya "
"fuera de contexto. Pronto compruebas que se trata del suelo, ves como desde el "
"nordeste hasta aqui hay un bien definido camino de ramas y ojas apartadas, como "
"si alguien hubiese arrastrado algo hasta el lugar en el que te encuentras. "
"Al nordeste ves un gran arbol con una extranya construccion de madera en su "
"copa, parece una pequenya cabanya o una torreta de vigilancia.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("este",Z_BOSQUE("bosque_30"));
  AddExit("nordeste",Z_BOSQUE("bosque_40"));
  AddExit("norte",Z_BOSQUE("bosque_39"));
  AddDetail(({"arbol","cabanya","construccion","torreta"}),
  "De entre todos los arboles, el que mas te llama la atencion es uno que se "
  "encuentra situado al nordeste de tu posicion y en el que, al parecer, hay una "
"construccion de madera en su copa.\n");
  AddDetail(({"arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado...\n");
  AddDetail(({"suelo","tierra"}),
  "Te arrodillas para examinar la tierra que hay bajo tus pies, tratando de "
  "encontrar una tumba o algo por el estilo. Pero es inutil, lo que hubiera sido "
  "arrastrado hasta aqui hace mucho que desaparecio.\n");
  SetIntNoise("Oyes silvar las ojas mecidas por el viento.\n");
  SetIntSmell("Uele a podrido...\n");
  SetLocate("bosque de Zarkam");
}
