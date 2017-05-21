/*=============================================================*
 |                  << Atun cheto@simauria >>                  |
 *=============================================================*
 |               Ultima Modificacion.. 16-11-98                |
 |             adaptacion de la naranja de limbo               |
 |     Nemesis: Puesto size y weight a 0 pa que pueda ello     |
 |     Zomax: Pongo que no se pueda robar, tirar, comprar y    |
 |            la función de dar solo al cocinero del quest     |
 |            en lugar de SetNoGive(1) porque usan el dar      |
 |            de verdad.
 *=============================================================*/

#include "path.h"
#include <properties.h>

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes un atun crudo\n");
   SetFoodStuff(10);
   SetFoodHeal(10);
   SetShort("un atun");
   SetLong("Es un atun, un vulgar pescado.\n");
   AddId("pescado");
   AddId("atun");
   AddId("comida");
   AddId("qatun");
   SetSize(0);
   SetWeight(0);
   Set(P_NOSELL,1); //poke es necerario p'al quest
   Set(P_CANT_STEAL,1);
   SetNoDrop(1);
   Set(P_NOSELL,1);
}

init(){
  ::init();

  add_action("fdar","dar");

}

public int fdar(string str)
{
	object cocinero;
	string cosa,quien;

	if (!str  || sscanf(str,"%s a %s",cosa,quien) != 2) return 0;
	if (environment(TP) && id(cosa))
	{
		cocinero=present(quien,environment(TP));
		if (cocinero && (living(cocinero)) && (cocinero->id("cocinero"))) return 0;
		else
		{
			write("No puedes dar el atún.\n");
			return 1;
		}
	}
}
