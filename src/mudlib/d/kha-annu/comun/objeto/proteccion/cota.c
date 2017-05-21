/* Cota de malla por Izet@Simauria. 30/10/98
Retocada por [Y] Yandros para Kha-annu. 31/10/98 */

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>


inherit ARMOUR;

create() {
   ::create();
  SetStandard(AT_ARMOUR,2,P_SIZE_MEDIUM,M_ACERO);
   SetShort("una cota de malla");
  SetLong(
"Es una cota de malla corta, que solo te cubre el torso. No tiene ningun\n"
"adorno en particular y parece una armadura ligera.\n");
   SetIds( ({"cota","cota malla","cota de malla"}) );
   SetAds( ({"una","la"}) );
  SetMaterial("metal");
   Set(P_GENDER,GENDER_FEMALE);
  SetWeight(4000);
   SetValue(140);
}
