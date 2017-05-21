//viejom.c
//Hecho por Ghandor
//4 de diciembre de 1997
// [Woo] Modificado

#include "path.h"
#include <properties.h>

inherit KBASE;

int dicho;

create() {
  ::create();
  SetStandard("Bior","enano",3,GENDER_MALE);
  SetShort("Bior, el funcionario");
  SetLong(
"Este es el guardia de la garita. Su trabajo consiste en vigilar quien entra y\n"
"quien sale de la Escuela. Es un enano de cerca de los 300 anyos. Su cabello es\n"
"blanco como la nieve, igual que su barba. Aunque es demasiado viejo sus ojos\n"
"desprenden una fuerza impresionante, sin duda alguna, en su juventud fue uno\n"
"de los mayores guerreros de la ciudad. Es un viejo cascarrabias.\n");
  SetIds(({"enano","funcionario","el funcionario","al funcionario"}));
  SetNoGet("Bior no es tu tipo.\n");
  InitAChats(8,({
   "Solo me faltaba esto, poco salario y un imbecil que me ataque!"
  }));
}


public varargs void Die(mixed silent) {
   tell_room(environment(TO),
          TO->QueryShort()+" cae al suelo inconsciente y manando sangre en "
          "abundancia.\n");
   TP->SetAttribute("asesino",(TP->QueryAttribute("asesino"))+1);
   ::Die(silent);
}
