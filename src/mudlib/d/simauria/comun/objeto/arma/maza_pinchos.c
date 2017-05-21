/*
  maza_pinchos.c
  (c) Nemesis@Simauria

  Una maza de pinchos. Se maneja como maza, pero
  corta como una espada.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MAZA, 6, P_SIZE_GENERIC, M_ACERO);
   SetShort("una maza de pinchos");
   SetLong("Es una maza metálica cubierta de puntiagudos pinchos.\n");
   AddId(({"maza de pinchos"}));
   SetDamType(DT_SLASH);
   SetQuality(90);
}
