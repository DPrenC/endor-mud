/* Casco de hierro
   Theuzifan, 29-03-99
*/

inherit ARMOUR;
#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

create()
{
  ::create();
 SetStandard(AT_HELMET, 3, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("un casco de hierro");
  SetLong("Es un casco de hierro hábilmente forjado.\n");
  SetIds(({"casco", "casco de hierro"}));
  Set(P_GENDER, GENDER_MALE);
}
