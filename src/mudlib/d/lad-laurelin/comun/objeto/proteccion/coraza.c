/* Coraza de cuero estándar
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
 SetStandard(AT_CORAZA, 6, P_SIZE_MEDIUM, M_CUERO);
  SetShort("una coraza de cuero");
  SetLong("Es una coraza de cuero bastante burda.\n");
  SetIds(({"coraza", "coraza de cuero"}));
  Set(P_GENDER, GENDER_FEMALE);
}