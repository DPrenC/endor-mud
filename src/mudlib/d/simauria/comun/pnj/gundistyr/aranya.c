/* aranya.c
Autor: [n] Nemesis@simauria
Descripci�n: Una ara�a que hay por los pasadizos de la cueva
Modificado: 26-Jul-2001 [n] Creaci�n
*/

#include <rooms.h>
#include <properties.h>

inherit NPC;

create() {
  ::create();
  SetStandard("una ara�a grande","ara�a",5,GENERO_FEMENINO);
  SetShort("una asquerosa ara�a");
  SetLong(
  "Es una ara�a de color negro y rojo, toda peluda y con esos ojos\n"
  "tan particulares que la hacen tan asquerosa. Mide unos 25 cm de\n"
  "di�metro, patas incluidas, pero no parece ser peligrosa, tan solo\n"
  "da asco.\n");
  SetIds(({"aranya","ara�a"}));
  SetAds(({"una","asquerosa","gran"}));
  SetLevel(3);
  SetAlign(0);
  SetSize(P_SIZE_SMALL);
  SetMaxHP(20);
  SetHP(20);
  SetGender(GENDER_MALE);
  SetHands(({({"mordisco",0,6}),({"mordisco",0,6})}));
  InitChats(5,({
   "La ara�a te mira con cara de hambre.\n",
   "La ara�a se balancea en su tela.\n"
  }));

}

public varargs void Die(mixed silent) {
RemoveId("aranya");
::Die(silent);
}
