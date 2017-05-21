/*
  hacha_mano.c
  (c) Nemesis@Simauria

  Una simple hacha de mano.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_HACHA, 3, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un hacha de mano");
   SetLong("Una vieja hacha de mano.\n");
   AddId(({"hacha","hacha de mano"}));
   SetResetQuality(80);
   SetQuality(60+random(5)+random(10)+random(5));
}
