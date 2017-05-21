/* Coraza de cuero claveteado
   Theuzifan, 29-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_ARMOUR, 12, P_SIZE_MEDIUM, M_CUERO);
  SetShort("una coraza de cuero claveteado");
  SetLong("Es una coraza de cuero clavetado.\n");
  SetIds(({"coraza", "coraza de cuero claveteado"}));
  Set(P_GENDER, GENDER_FEMALE);
}
