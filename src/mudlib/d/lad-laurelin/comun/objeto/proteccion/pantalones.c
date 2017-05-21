/* Pantalones de cuero estándar
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
 SetStandard(AT_PANTALONES, 2, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unos pantalones de cuero");
  SetLong("Son unos pantalones de cuero que te protegerán un poco.\n");
  SetIds(({"pantalones", "pantalones de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}