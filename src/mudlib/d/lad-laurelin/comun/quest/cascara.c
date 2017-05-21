/* Cascara de Wyvelt (pajarraco)
   Theuzifan, 30-09-99, Creaci�n
*/

#include "path.h"
#include <properties.h>

inherit THING;

create()
{
  ::create();
  SetShort("un trozo de c�scara de un huevo de Wyvelt");
  SetLong(W("Es una parte de la c�scara del huevo de alg�n polluelo de "
  	"Wyvelt. Su color es verde oliv�ceo, y te llama la atenci�n su "
  	"gran dureza y su poco peso.\n"));
  SetIds(({"c�scara", "cascara"}));

  SetWeight(10000);
  SetValue(0);
  Set(P_MAGIC, 1);
}