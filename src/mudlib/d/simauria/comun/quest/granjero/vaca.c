/*   vaca.c
     Creada por : Nemesis
     Fecha 3-Dic-97
	 Revisada por : Nemesis
	 No puedo evitarlo... soy un perfeccionista.
     [n] Castellanizado. (Oct'02)
     [Ratwor] la estandarizo y la retoco lijeramente. 25/04/2010
*/
#include <properties.h>
#include <damage.h>
inherit NPC;


create() {
    ::create();
    SetStandard("una vaca", "vaca", 20, GENDER_FEMALE);
    SetShort("una vaca lechera");
    SetLong("Es una vaca lechera, no es una vaca cualquiera.\n Toda blanca y con "
    "sus grandes manchas negras.\n");
    AddId(({"vaca_lechera","vaca"}));
    SetWeight(400000);
    SetAds(({"lechera"}));
    SetHP(QueryHP()*2); 
    SetAC(20);
    SetHands(({({"la pata delantera derecha",TD_APLASTAMIENTO,4}),
	     ({"la pata delantera izquierda",TD_APLASTAMIENTO,4}),
	     ({"los cuernos",TD_PENETRACION,7})}));
    InitChats(10,({
	"La vaca dice: '¡MuuUUUUUUUUU!'\n",
	"La vaca come un poco de heno.\n",
	"La vaca espanta una mosca con el rabo.\n",
	"La vaca te mira.\n",
	"La vaca se ríe.\n",
  }));
  InitAChats(10,({
	"La vaca muge lastimosamente.\n",
  }));
}
