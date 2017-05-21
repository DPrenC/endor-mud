/* Botas de montañismo para escalada. [Y] Yandros */

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

create() {
   ::create();
   SetStandard(AT_BOOTS,2,P_SIZE_MEDIUM,M_CUERO);
   SetShort("unas botas de escalada");
   SetLong(
"Son unas botas de montaña muy apropiadas para la escalada. Tienen unos dientes\n"
"en forma de sierra en su base. Parecen algo pesadas.\n");
   SetIds( ({"botas","botas de escalada","botas de montañismo",
             "botas de montaña","botas_escalada"}) );
   SetAds( ({"unas","las"}) );
   Set(P_GENDER,GENDER_FEMALE);
   SetWeight(5500);
   SetValue(105);
   Set(P_NUMBER,NUMBER_PLURAL);
}
