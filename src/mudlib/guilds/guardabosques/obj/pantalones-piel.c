/* Pantalones de piel de reptil
   Theuzifan, 10-03-99
*/	

inherit "/std/armour";
#include "path.h"
#include <materials.h>

create()
{
  ::create();
 SetStandard(AT_PANTALONES, 3, P_SIZE_MEDIUM, M_TELA);
  SetShort("unos pantalones de piel");
  SetLong("Son unos pantalones de piel de alg�n reptil de la zona.\n");
  SetIds(({"pantalones", "pantalones de piel"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}
