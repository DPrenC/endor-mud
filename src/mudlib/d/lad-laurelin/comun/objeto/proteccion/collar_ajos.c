/* Un collar de ajos (pfff, menudo tufillo ...)
   Alura 12/6/2000
*/

inherit ARMOUR;
#include "path.h"
#include <combat.h>
#include <properties.h>

create()
{
  ::create();
 SetStandard(AT_AMULET, 0, P_SIZE_MEDIUM);
  SetShort("un collar de ajos");
  SetLong("Es un collar de ajos tiernos que huele que apesta ...\n");
  SetIds(({"ajo","collar de ajos","collar"}));
  Set(P_NUMBER, NUMBER_PLURAL);
  Set(P_GENDER, GENDER_MALE);
}