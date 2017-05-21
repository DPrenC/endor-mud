/* Vara de madera
   Theuzifan, 10-03-99
*/

inherit WEAPON;

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

create() {
  ::create();
 SetStandard(WT_VARA, 5, P_SIZE_MEDIUM, M_MADERA);
  SetShort("una vara de madera");
  SetLong(W("Es una vara de madera confeccionada con una madera bastante "
  	"resistente. En el centro tiene dos asideros de cuero para que no "
  	"se lastimen las manos de quien la empuña.\n"));
  Set(P_NUMBER_HANDS, 2);
  Set(P_GENDER, GENDER_FEMALE);
}
