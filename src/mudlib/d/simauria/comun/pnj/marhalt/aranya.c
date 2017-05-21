/*   aranya.c
	  Creada por : Blackrider
	  Fecha 6-6-97
	  Corregida por:
	  [m] Mirill (Nov'97)
	  [n] Nemesis (Dic'97)
 Nemesis te dice: Pero tio! Como le pones WC 10 a la aranyita!
 Si ese es el WC maximo de una maza de madera!!!! Pero tu estas bien?
          [n] Castellanizado. (Oct'02)
*/

inherit NPC;
#include <living.h>
#include <combat.h>

create() {
  ::create();
  SetShort("una araña negra");
  SetLong("Es una araña negra pero no parece maligna.\n");
SetName("araña");
  SetRace("aranya");
  SetGender(GENDER_NEUTER);
  SetNoise("Oyes como la aranya teje una telaranya.\n"); // Vaya, no sabia yo que "eso" se oia...
  SetWeight(15); // 1/2 Kilo una aranya??? PERO TIO!!!
SetIds(({"aranya"}));
  SetAds(({"negra"}));
  SetLevel(1);
  SetAlign(0);
  SetHP(10);
  SetMaxHP(10);
  SetHands(({({"la pata delantera derecha",0,1}),
		  ({"la pata delantera izquierda",0,1}),
		  }));
  InitChats(10,({
	"La araña intenta tejer una telaraña en tu pelo.\n",
  }));
}
