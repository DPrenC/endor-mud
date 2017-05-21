/*
  arpon.c
  (c) Nemesis@Simauria

  Un arp�n que ser�a la envidia del mism�simo Ned Land...
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_LANZA, 4, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un arp�n");
   SetLong("Un temible arp�n de punta dentada. Parece muy peligroso.\n");
   AddId(({"arp�n","lanza","arpon"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(85);
}
