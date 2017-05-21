/* T�nica de tela
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

 SetStandard(AT_CLOAK, 3, P_SIZE_MEDIUM, M_TELA);
  SetShort("una t�nica de tela");
  SetLong("Es una t�nica de tela bien confeccionada. Puesta suele llegar "
	"hasta pr�cticamente el suelo, claro que esto suele depender de "
	"qui�n se lo ponga.\n");
  SetIds(({"tunica", "t�nica", "tunica de tela", "t�nica de tela"}));
  Set(P_GENDER, GENDER_FEMALE);
}
