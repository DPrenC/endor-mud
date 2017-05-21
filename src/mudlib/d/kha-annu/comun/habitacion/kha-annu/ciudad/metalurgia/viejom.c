//viejom.c
//Hecho por Ghandor
//4 de diciembre de 1997

#include <properties.h>

#include <living.h>
#include <combat.h>

inherit NPC;

int dicho;

create() {
      ::create();

  SetStandard("Lophekz","enano",10,GENDER_MALE);
  SetShort("Lophekz, el funcionario");
  SetLong(
"Este es el guardia de la garita. Su trabajo consiste en vigilar quien entra y "
"quien sale de la Escuela. Es un enano de cerca de los 300 años. Su cabello es "
"blanco como la nieve, igual que su barba. Aunque es demasiado viejo sus ojos "
"desprenden una fuerza impresionante, sin duda alguna, en su juventud fue uno "
"de los mayores guerreros de la ciudad. Es un viejo cascarrabias.\n");
  SetIds(({"enano","funcionario","el funcionario","al funcionario"}));
  SetNoGet("Que haces burro?\n");
  InitAChats(8,({
   "Solo me faltaba esto, poco salario y un imbecil que me ataque!"
  }));
}

