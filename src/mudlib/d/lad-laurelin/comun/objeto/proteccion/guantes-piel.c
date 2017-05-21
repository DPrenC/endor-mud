/* Guantes de piel
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
 SetStandard(AT_GUANTES, 0, P_SIZE_MEDIUM, M_TELA);
  SetShort("unos guantes de piel");
  SetLong(W("Son unos bonitos guantes de piel, que obviamente no te "
	"protegerán de ningún golpe, pero te darán ese toque de "
	"distinción que mucha gente desea...\n"));
  SetIds(({"guantes", "guantes de piel"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}
