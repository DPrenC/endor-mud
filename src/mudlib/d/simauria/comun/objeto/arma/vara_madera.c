/*
  vara_madera.c
  (c) Nemesis@Simauria

  Una simple vara de madera. Podría ser un
  antiguo palo de escoba.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_VARA, 3, P_SIZE_GENERIC, M_MADERA);
   SetShort("una vara larga");
   SetLong("Una larga vara de madera. Un arma simple, pero efectiva.\n");
   AddId(({"vara","vara larga"}));
   SetResetQuality(90);
   SetQuality(85);
}
