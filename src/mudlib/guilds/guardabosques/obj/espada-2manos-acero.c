/* Espada de dos manos
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_ESPADA, 11, P_SIZE_MEDIUM, M_ACERO);
  SetShort("una espada de dos manos de acero");
  SetLong(W("Es una larga y pesada espada de dos manos hecha de una fina "
  	"aleación de acero rígido y de hierro más maleable. El resultado es "
  	"una magnífica espada de dos manos perfecta para el combate.\n"));
  SetIds(({"espada", "espada de dos manos", "espadón", "espadon"}));
  Set(P_NUMBER_HANDS, 2);
  Set(P_GENDER, GENDER_FEMALE);
}