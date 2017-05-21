/* Lucero del alba
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
 SetStandard(WT_MANGUAL, 12, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("un lucero del alba");
  SetLong(W("Es un lucero del alba pesado, de dos manos. Está compuesto por "
  	"una increíblemente grande bola de metal con grandes pinchos unida "
  	"a un largo mango metálico para las dos manos por una pesada cadena, "
  	"también de metal.\n"));
  SetIds(({"lucero", "lucero del alba"}));
  Set(P_NUMBER_HANDS, 2);
}