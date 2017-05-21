/* Bote de aguamiel
   Theuzifan, 10-03-99
*/

inherit FOOD;
#include "path.h"
#include <health.h>

create()
{
  ::create();

  SetShort("un bote de aguamiel");
  SetLong(W("Es un bote que contiene un poco de aguamiel, una exquisita bebida "+
  	"muy valorada, aparte por su sabor, por sus propiedades curativas.\n"));
  SetSmell("Huele estupendamente.\n");
  SetIds(({"bote", "aguamiel", "bote de aguamiel"}));
  SetWeight(150);
  SetDrink();
  SetFoodAlc(10);
  SetFoodSoak(20);
  SetFoodStuff(20);
}
  