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
  	"aleaci�n de acero r�gido y de hierro m�s maleable. El resultado es "
  	"una magn�fica espada de dos manos perfecta para el combate.\n"));
  SetIds(({"espada", "espada de dos manos", "espad�n", "espadon"}));
  Set(P_NUMBER_HANDS, 2);
  Set(P_GENDER, GENDER_FEMALE);
}