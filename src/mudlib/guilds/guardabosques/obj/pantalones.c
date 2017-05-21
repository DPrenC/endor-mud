/* Pantalones de cuero estándar
   Theuzifan, 10-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_PANTALONES, 2, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unos pantalones de cuero");
  SetLong("Son unos pantalones de cuero que te protegerán un poco.\n");
  SetIds(({"pantalones", "pantalones de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}