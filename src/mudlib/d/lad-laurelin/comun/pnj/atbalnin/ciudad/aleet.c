/*
	Aleet la herrera
	Theuzifan, 14-03-99
*/
	
#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
  ::create();

  SetStandard("aleet", "elfo", 5, GENDER_FEMALE);
  SetShort("Aleet la herrera");
  SetLong(W("Aleet es la esposa de Ralin, y juntos tienen una de las mejores "
  	"herrerías de Lad Laurelin.\n"));
  	
  InitChats(1,({
  	"Aleet golpea el yunque con su martillo.\n",
  	"Aleet se seca el sudor de una manera... encantadora.\n",
  	"Aleet coge una pieza de una armadura y se dispone a repararla.\n"}));
}
