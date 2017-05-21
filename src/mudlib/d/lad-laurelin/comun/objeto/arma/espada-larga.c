/* Espada larga
   Theuzifan, 10-03-99
*/

#include "path.h"
#include <combat.h>
#include <properties.h>#include <combat.h>
#include <materials.h>

inherit WEAPON;


create()
{
  ::create();
 SetStandard(WT_ESPADA, 8, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una espada larga");
  SetLong(W("Es una espada larga de una mano. La hoja es bastante grande, "
  	"midiendo algo más de un metro, y no tiene ningún signo distintivo.\n"));
  SetIds(({"espada", "espada larga"}));
  Set(P_GENDER, GENDER_FEMALE);
}