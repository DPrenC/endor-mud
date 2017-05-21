/* Escudo de madera
   Theuzifan, 29-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_ESCUDO, 2, P_SIZE_MEDIUM, M_MADERA);
  SetShort("un escudo redondo de madera");
  SetLong("Es el típico escudo redondo de madera.\n");
  SetIds(({"escudo", "escudo de madera", "escudo redondo"}));
}
