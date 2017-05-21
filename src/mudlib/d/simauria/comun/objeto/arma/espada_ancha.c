/*
  espada_ancha.c
  (c) Nemesis@Simauria

  Una simple espada ancha.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_ESPADA, 5, P_SIZE_GENERIC, M_ACERO);
   SetShort("una espada ancha");
   SetLong("Es una poderosa espada ancha.\n");
   AddId(({"espada","espada ancha"}));
   SetResetQuality(85);
   SetQuality(85);
}
