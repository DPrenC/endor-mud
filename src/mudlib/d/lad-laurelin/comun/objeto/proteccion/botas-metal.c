/* Botas de hierro
   Theuzifan, 29-03-99
*/

#include "path.h"
#include <combat.h>
#include <properties.h>

inherit ARMOUR;

create()
{
  ::create();
 SetStandard(AT_BOTAS, 3, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("unas botas de hierro");
  SetLong("Son un par de botas de cuero cubiertas con láminas de hierro.\n");
  SetIds(({"botas", "botas de hierro"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER, NUMBER_PLURAL);
}
