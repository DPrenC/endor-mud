/* Casco de hierro
   Theuzifan, 29-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_HELMET, 3, P_SIZE_MEDIUM, M_CUERO);
  SetShort("un casco de cuero");
  SetLong("Es un simple casco de cuero.\n");
  SetIds(({"casco", "casco de cuero"}));
  Set(P_GENDER, GENDER_MALE);
}
