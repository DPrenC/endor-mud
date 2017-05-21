/* Espada de dos manos
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_VARA, 9, P_SIZE_MEDIUM, M_MADERA);
  SetShort("una vara de madera");
  SetLong(W("Es una larga y flexible vara de madera. Tiene una especie de "
  	"agarraderas de cuero para una utilización más cómoda.\n"));
  SetIds(({"vara", "vara de madera"}));
  Set(P_NUMBER_HANDS, 2);
  Set(P_GENDER, GENDER_FEMALE);
}