/* Guantes de cuero estándar
   Theuzifan, 10-03-99
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

create()
{
  ::create();
 SetStandard(AT_GUANTES, 1, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unos guantes de cuero");
  SetLong("Son unos guantes de cuero normalitos.\n");
  SetIds(({"guantes", "guantes de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}