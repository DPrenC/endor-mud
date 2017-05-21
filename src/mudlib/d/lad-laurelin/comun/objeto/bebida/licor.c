/* Bote de licor
   Theuzifan, 10-03-99
*/

inherit FOOD;
#include "path.h"
#include <health.h>

create()
{
  ::create();

  SetShort("un bote de licor");
  SetLong(W("Es un bote que contiene un fuerte licor, de un color oscuro y "+
  	"un olor bastante fuerte.\n"));
  SetSmell("Tiene un olor muy fuerte, y un poco afrutado.\n");
  SetIds(({"bote", "licor", "bote de licor"}));
  SetWeight(50);
  SetDrink();
  SetFoodAlc(15);
  SetFoodSoak(15);
}
  