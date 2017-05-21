/* Fichero: arpon.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;
create() {
::create();
   SetStandard(WT_JABALINA, 8, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un arpón");
   SetLong("Un temible arpón de punta dentada. Parece muy peligroso.\n");
   AddId(({"arma", "arpón","arpon"}));
    Set(P_GENDER, GENDER_MALE);
      }
