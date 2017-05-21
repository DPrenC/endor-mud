/* Lucero del alba de plata
   Alura, 04/07/01
*/

inherit WEAPON;
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

create()
{
  ::create();
 SetStandard(WT_MANGUAL, 9, P_SIZE_MEDIUM, M_PLATA);
  SetShort("un lucero del alba");
  SetLong(W("Es un lucero del alba pesado, de dos manos. Est� compuesto por "
  	"una incre�blemente grande bola de metal plateada con grandes pinchos unida "
  	"a un largo mango met�lico para las dos manos por una pesada cadena, "
  	"tambi�n de metal.\n"));
  SetIds(({"lucero", "lucero del alba"}));
  SetValue(10000);
  Set(P_NUMBER_HANDS, 2);
}