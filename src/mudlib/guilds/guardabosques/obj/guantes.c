/* Guantes de cuero estándar
   Theuzifan, 10-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_GUANTES, 1, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unos guantes de cuero");
  SetLong("Son unos guantes de cuero normalitos.\n");
  SetIds(({"guantes", "guantes de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}