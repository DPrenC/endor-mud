/* Hacha de combate, una mano
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
 SetStandard(WT_HACHA, 6, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una hacha de combate");
  SetLong(W("Es una hacha de combate de una mano. La hoja está firmemente "
  	"sujeta al mango de madera. Esta hacha es sólo de simple hoja, y se "
  	"coge usando una sola mano, lo que da más libertad para usar otra "
  	"arma o un escudo.\n"));
  SetIds(({"hacha", "hacha de combate"}));
  Set(P_GENDER, GENDER_FEMALE);
}