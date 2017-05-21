STANDAR
/* Capa de tela
   Theuzifan, 10-03-99
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

create()
{
  ::create();
 SetStandard(AT_MANTO, 1, P_SIZE_LARGE, M_TELA);
  SetShort("una capa de tela");
  SetLong("Es una capa de tela ordinaria.\n");
  SetIds(({"capa", "capa de tela"}));
  Set(P_GENDER, GENDER_FEMALE);
}
