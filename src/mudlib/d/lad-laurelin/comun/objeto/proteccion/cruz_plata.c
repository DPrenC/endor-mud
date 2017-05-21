/* Una cruz de plata
   Alura 12/6/2000
*/

inherit ARMOUR;
#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

create()
{
  ::create();
 SetStandard(AT_BROCHE, 1, P_SIZE_LARGE, M_PLATA);
  SetShort("una cruz");
  SetLong("Es una brillante cruz.\n");
  SetIds(({"cruz","cruz de plata"}));
  Set(P_NUMBER, NUMBER_SINGULAR);
  Set(P_GENDER, GENDER_FEMALE);
}