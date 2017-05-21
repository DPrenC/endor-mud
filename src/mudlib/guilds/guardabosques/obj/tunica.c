/* Túnica de tela
   Theuzifan, 10-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_CLOAK, 3, P_SIZE_MEDIUM, M_TELA);
  SetShort("una túnica de tela");
  SetLong("Es una túnica de tela bien confeccionada. Puesta suele llegar "
	"hasta prácticamente el suelo, claro que esto suele depender de "
	"quién se lo ponga.\n");
  SetIds(({"tunica", "túnica", "tunica de tela", "túnica de tela"}));
  Set(P_GENDER, GENDER_FEMALE);
}
