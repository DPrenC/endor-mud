/*
  maza_madera.c
  (c) Nemesis@Simauria

  Una maza de madera hecha polvo.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MAZA, random(2)+1, P_SIZE_GENERIC, M_MADERA);
   SetShort("una maza de madera");
   SetLong("Es una carcomida maza de madera.\n");
   AddId(({"maza","maza de madera"}));
   SetResetQuality(85);
   SetQuality(65+random(5)+random(10)+random(25));
}
