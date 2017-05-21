/* Escudo de hierro (ligero)
   Theuzifan, 29-03-99
*/

inherit ARMOUR;
#include "path.h"
#include <combat.h>
#include <materials.h>
#include <properties.h>

create()
{
  ::create();
 SetStandard(AT_ESCUDO, 2, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("un escudo de metal");
  SetLong("Es un escudo de hierro sin ningún emblema.\n");
  SetIds(({"escudo", "escudo de hierro"}));
}
