/* Cota de malla por Izet@Simauria. 30/10/98
Retocada por [Y] Yandros para Kha-annu. 31/10/98
[Woo] Modificada */

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>


inherit ARMOUR;

create() {
   ::create();
SetStandard(AT_ARMOUR,3,P_SIZE_MEDIUM,M_ACERO);
   SetShort("una cota de malla con mangas");
   SetLong(
"Es una cota de malla con mangas. Parece algo pesada, pero ademas del torso\n"
"también te cubre los brazos. No tiene ningún detalle en especial.\n");
   SetIds( ({"cota larga","cota con mangas","cota de malla con mangas"}) );
   SetAds( ({"una","la"}) );
Set(P_MATERIAL,"acero");
   Set(P_GENDER,GENDER_FEMALE);
   SetWeight(7000);
   SetValue(240);
}
