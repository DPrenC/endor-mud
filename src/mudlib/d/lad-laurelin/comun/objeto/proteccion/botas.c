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
 SetStandard(AT_BOTAS, 2, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unas botas de cuero");
  SetLong("Son unas botas de cuero bastante ordinarias.\n");
  SetIds(({"botas", "botas de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
  Set(P_GENDER, GENDER_FEMALE);
}