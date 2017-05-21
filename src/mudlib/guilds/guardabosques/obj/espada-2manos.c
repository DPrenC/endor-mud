/* Espada de dos manos
   Theuzifan, 10-03-99
*/	

inherit "/std/weapon";
#include "path.h"

create()
{
  ::create();
 SetStandard(WT_ESPADA, 10, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("una espada de dos manos");
  SetLong(W("Es una larga y pesada espada de dos manos. El mango met�lico "
  	"est� rodeado por tiras de cuero, y la larga hoja est� bien tallada, "
  	"con el peso repartido uniformemente.\n"));
  SetIds(({"espada", "espada de dos manos", "espad�n", "espadon"}));
  Set(P_NUMBER_HANDS, 2);
  Set(P_GENDER, GENDER_FEMALE);
}