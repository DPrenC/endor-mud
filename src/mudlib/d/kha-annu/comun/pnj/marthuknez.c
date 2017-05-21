//viejo.c
//Hecho por Ghandor
//2 de diciembre de 1997


#include "path.h"
#include <properties.h>

inherit NPC;

int dicho;

create() {
  ::create();
  SetStandard("Godar","enano",4,GENDER_MALE);
  SetShort("Godar, el funcionario");
  SetLong(
"Este es el guardia de la garita. Su trabajo consiste en vigilar quien entra y\n"
"quien sale de la Escuela. Es un enano de cerca de los 300 anyos. Su cabello es\n"
"blanco como la nieve, igual que su barba. Aunque es demasiado viejo sus ojos\n"
"desprenden una fuerza impresionante, sin duda alguna, en su juventud fue uno\n"
"de los mayores guerreros de la ciudad. Es un viejo cascarrabias.\n");
  SetIds(({"enano","funcionario","el funcionario","al funcionario"}));
  SetNoGet("Godar no es tu tipo.\n");
  InitAChats(8,({
   "¡Socorro! ¡Hay asesinos en Kha-annu! ¡GUARDIAS!\n"
  }));
}


public varargs void Die(mixed silent) {
   tell_room(environment(TO),
"Godar cae al suelo de espaldas con la cara destrozada y sangrando por los\n"
"oidos y la nariz.\n");
   TP->SetAttribute("asesino",(TP->QueryAttribute("asesino"))+1);
   ::Die(silent);
}
