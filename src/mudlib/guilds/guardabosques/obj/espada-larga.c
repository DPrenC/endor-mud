/* Espada larga
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

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