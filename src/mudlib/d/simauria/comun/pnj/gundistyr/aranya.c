/* aranya.c
Autor: [n] Nemesis@simauria
Descripción: Una araña que hay por los pasadizos de la cueva
Modificado: 26-Jul-2001 [n] Creación
*/

#include <rooms.h>
#include <properties.h>

inherit NPC;

create() {
  ::create();
  SetStandard("una araña grande","araña",5,GENERO_FEMENINO);
  SetShort("una asquerosa araña");
  SetLong(
  "Es una araña de color negro y rojo, toda peluda y con esos ojos\n"
  "tan particulares que la hacen tan asquerosa. Mide unos 25 cm de\n"
  "diámetro, patas incluidas, pero no parece ser peligrosa, tan solo\n"
  "da asco.\n");
  SetIds(({"aranya","araña"}));
  SetAds(({"una","asquerosa","gran"}));
  SetLevel(3);
  SetAlign(0);
  SetSize(P_SIZE_SMALL);
  SetMaxHP(20);
  SetHP(20);
  SetGender(GENDER_MALE);
  SetHands(({({"mordisco",0,6}),({"mordisco",0,6})}));
  InitChats(5,({
   "La araña te mira con cara de hambre.\n",
   "La araña se balancea en su tela.\n"
  }));

}

public varargs void Die(mixed silent) {
RemoveId("aranya");
::Die(silent);
}
