/*
  arpon.c
  (c) Nemesis@Simauria

  Un arpón que sería la envidia del mismísimo Ned Land...
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_LANZA, 4, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un arpón");
   SetLong("Un temible arpón de punta dentada. Parece muy peligroso.\n");
   AddId(({"arpón","lanza","arpon"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(85);
}
