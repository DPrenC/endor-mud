/* Botas de cuero, re-editada por [Y] Yandros de una armadura simple */
/* creada por Izet@simauria.upv.es. 30/10/98 */
/* [Woo] Modificada */

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

create() {
   ::create();
   SetStandard(AT_BOOTS,1,P_SIZE_MEDIUM,M_CUERO);
   SetShort("unas botas de cuero");
   SetLong("Son unas botas de cuero anchas y robustas.\n");
   SetIds( ({"botas","botas de cuero","botas anchas","botas robustas"}) );
   SetAds( ({"unas","las"}) );
  Set(P_GENDER,GENDER_FEMALE);
   SetWeight(1000);
   SetValue(60);
  Set(P_NUMBER,NUMBER_PLURAL);
}
