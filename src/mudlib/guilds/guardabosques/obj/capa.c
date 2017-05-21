/* Capa de tela
   Theuzifan, 10-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_CLOAK, 2, P_SIZE_MEDIUM, M_TELA);
  SetShort("una capa de tela");
  SetLong("Es una capa de tela ordinaria.\n");
  SetIds(({"capa", "capa de tela"}));
  Set(P_GENDER, GENDER_FEMALE);
}
