/* Coraza de piel de reptil
   Theuzifan, 10-03-99
*/	

inherit "/std/armour";
#include "path.h"

create()
{
  ::create();
 SetStandard(AT_CORAZA, 8, P_SIZE_MEDIUM, M_TELA);
  SetShort("una coraza de piel");
  SetLong(W("Es una coraza hecha de la piel de alg�n reptil Este animal "
	"deb�a ser bastante resistente ya que esta prende ofrece una buena "
	"protecci�n.\n"));
  SetIds(({"coraza", "coraza de piel"}));
  Set(P_GENDER, GENDER_FEMALE);
}
