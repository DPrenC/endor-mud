/* Coraza de mallas
   Theuzifan, 29-03-99
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;


create()
{
  ::create();
 SetStandard(AT_ARMOUR, 12, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una coraza de malla");
  SetLong("Es una coraza de malla laboriosamente construida.\n");
  SetIds(({"coraza", "coraza de malla"}));
  Set(P_GENDER, GENDER_FEMALE);
}
