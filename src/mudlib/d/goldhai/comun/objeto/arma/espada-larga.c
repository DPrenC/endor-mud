/* Espada larga
   Theuzifan, 10-03-99
   Maler tuvio aquin
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;


create()
{
  ::create();
 SetStandard(WT_ESPADA, 9, P_SIZE_LARGE, M_HIERRO);
  SetShort("una espada larga");
  SetLong("Es una espada larga de una mano. La hoja es bastante grande, midiendo. "
  "algo más de un metro, y no tiene ningún signo distintivo.\n");
  SetIds(({"espada", "espada larga"}));
  Set(P_GENDER, GENDER_FEMALE);
}