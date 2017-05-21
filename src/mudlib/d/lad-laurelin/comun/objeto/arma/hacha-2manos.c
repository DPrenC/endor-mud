/* Hacha de guerra, dos manos
   Theuzifan, 10-03-99
*/

inherit WEAPON;
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

create()
{
  ::create();
 SetStandard(WT_HACHA, 12, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("un hacha de guerra");
  SetLong(W("Es una hacha de guerra de dos manos. La pesada cabeza de dos "
  	"hojas est� sujeta a un largo mango met�lico.\n"));
  SetIds(({"hacha", "hacha de guerra"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER_HANDS, 2);
}