/* Vara de madera
   Alura, 2001
*/

inherit WEAPON;

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

create() {
  ::create();
 SetStandard(WT_VARA, 5, P_SIZE_MEDIUM, M_PLATA);
  SetShort("una vara plateada");
  SetLong(W("Es una vara recubierta con una filigrana de plata muy bella. "
  	"En el centro tiene dos asideros de piel para que no "
  	"se lastimen las manos de quien la empuña.\n"));
  Set(P_NUMBER_HANDS, 2);
  Set(P_GENDER, GENDER_FEMALE);
}
