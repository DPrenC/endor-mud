/* Pluma de Wyvelt (pajarraco)
   Theuzifan, 30-09-99, Creaci�n
*/

#include "path.h"
#include <properties.h>

inherit THING;

create()
{
  ::create();
  SetShort("una pluma de un polluelo de Wyvelt");
  SetLong(W("Es la pluma de un polluelo de un Wyvelt. Estas aves eran "
    	"muy hermosas y muy pero que muy grandes. Como la mayor�a de las "
    	"aves de leyenda, se dec�a que eran m�gicas, y que sus plumas "
    	"ten�an un alto valor curativo.\n"));
  SetIds(({"pluma"}));
  SetWeight(150);
  Set(P_MAGIC, 1);
}