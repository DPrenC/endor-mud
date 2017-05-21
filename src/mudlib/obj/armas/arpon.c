/* Fichero: arpon.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;
create() {
::create();
   SetStandard(WT_JABALINA, 8, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un arp�n");
   SetLong("Un temible arp�n de punta dentada. Parece muy peligroso.\n");
   AddId(({"arma", "arp�n","arpon"}));
    Set(P_GENDER, GENDER_MALE);
      }
