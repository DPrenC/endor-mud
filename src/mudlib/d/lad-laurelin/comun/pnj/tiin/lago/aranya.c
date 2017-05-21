/*   aranya.c
	  Creada por : Blackrider
	  Fecha 6-6-97
	  Corregida por:
	  Mirill (Nov'97)
	  Nemesis (Dic'97)
	  Seadrik(Oct'98) Poner el SetName para que cuando deje el cadaver
	  no sea de Juan Nadie.
 Nemesis te dice: Pero tio! Como le pones WC 10 a la aranyita!
 Si ese es el WC maximo de una maza de madera!!!! Pero tu estas bien?
*/

inherit NPC;
#include <living.h>
#include <combat.h>

create() {
  ::create();
 SetStandard("una araña negra","araña",1,GENDER_FEMALE);
  SetShort("una aranya negra");
  SetLong("Es una aranya negra pero no parece maligna.\n");
  SetNoise("Oyes como la aranya teje una telaranya.\n"); // Vaya, no sabia yo que "eso" se oia...
  SetWeight(15); // 1/2 Kilo una aranya??? PERO TIO!!!
  SetIds(({"aranya"}));
  SetAds(({"negra"}));
  SetAlign(0);
  SetHP(10);
  SetMaxHP(10);
  SetXP(0);
  SetHands( ({({"mordisco",0,1})}) );
  InitChats(10,({
	"La aranya intenta tejer una telaranya en tu pelo.\n",
	"Se le ha roto el hilo... la aranya se cae de golpe.\n",
	"A la aranya no le gusta como queda y vuelve a empezar.\n",
	"La aranya te mira.\n",
	"Podrias ser su presa, pero.... eres demasiado grande para ella.\n"
  }));
  InitAChats(10,({
	"La aranya se pasea por tu pie, que asco!\n"
  }));
}
