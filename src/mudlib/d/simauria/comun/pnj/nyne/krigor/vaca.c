/*   	vaca.c
     	27-11-01  Creada por : Chaos para krigor
	

*/
inherit NPC;

#include <living.h>
#include <combat.h>

create() {
  ::create();
 SetShort("una vaca lechera");
  SetLong("Es una vaca lechera, no es una vaca cualquiera.\n");
  SetName("vaca");
  AddId(({"vaca_lechera","vaca"}));
  SetRace("animal");
  SetGender(GENDER_FEMALE);
  SetWeight(300000);
  SetAds(({"lechera"}));
  SetLevel(8);
  SetAlign(0);
  SetAC(1);
  SetHands(({({"la pata delantera derecha",0,3}),
	     ({"la pata delantera izquierda",0,5}), //es zurda :o)
	     ({"los cuernos",0,6})}));
  InitChats(10,({
	"La vaca te dice: MuuUUUUUUUUU!\n",
	"La vaca come un poco.\n",
	"La vaca espanta una mosca con el rabo.\n",
	"La vaca te mira.\n",
	"La vaca se rie.\n"
  }));
  InitAChats(10,({
	"La vaca muge lastimosamente.\n"
  }));
}