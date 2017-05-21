/* Guantes de hierro
   Theuzifan, 29-03-99
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;


create()
{
  ::create();
 SetStandard(AT_GUANTES, 4, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("unos guantes de hierro");
  SetLong("Son unos pesados guantes de hierro.\n");
  SetIds(({"guantes", "guantes de hierro"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}
