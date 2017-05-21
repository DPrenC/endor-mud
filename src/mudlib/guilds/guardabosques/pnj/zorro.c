#include <living.h>
#include <properties.h>
#include "path.h"

inherit "/std/npc";

create()
{
  int level;
  ::create();

  level = 5 + random(3);

  SetStandard("un zorro", "zorro", level, GENDER_MALE);
  SetShort("un zorro");
  SetLong(W("Es un zorro. Parece mirar ansiosamente hacia más lugares de los que debiera. "
  	"Normalmente son animales bastante esquivos, aunque generalmente no "
  	"son peligrosos.\n"));
  SetWeight(20000);
  SetHands(({({"zarpa derecha",0,level/2}),
    	({"zarpa izquierda",0,level/2}),
    	({"mandíbula",0,level})}));
}
