/* Cascara de Wyvelt (pajarraco)
   Theuzifan, 30-09-99, Creación
*/

#include "path.h"
#include <properties.h>

inherit THING;

create()
{
  ::create();
  SetShort("un trozo de cáscara de un huevo de Wyvelt");
  SetLong(W("Es una parte de la cáscara del huevo de algún polluelo de "
  	"Wyvelt. Su color es verde oliváceo, y te llama la atención su "
  	"gran dureza y su poco peso.\n"));
  SetIds(({"cáscara", "cascara"}));

  SetWeight(10000);
  SetValue(0);
  Set(P_MAGIC, 1);
}