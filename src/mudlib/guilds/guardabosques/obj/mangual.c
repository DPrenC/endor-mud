/* Mangual
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_MANGUAL, 5, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una mangual");
  SetLong(W("Es una mangual de combate. Est� formado por una gran bola "
  	"met�lica con pinchos unida a un mango de madera por una pesada "
  	"cadena de metal.\n"));
  SetIds(({"mangual"}));
}