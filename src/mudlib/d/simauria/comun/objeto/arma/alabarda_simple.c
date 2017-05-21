/*
  alabarda_simple.c
  (c) Nemesis@Simauria

  La típica alabarda que todo guardia debe tener.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_ALABARDA, 8, P_SIZE_GENERIC, M_ACERO);
   SetShort("una alabarda de guardia");
   SetLong("Es una alabarda como las que usan los guardias. Tiene "
           "punta de lanza y una\nhoja parecida a la de un hacha "
           "en uno de los laterales del asta.\n");
   AddId(({"alabarda","alabarda de guardia"}));
   SetResetQuality(95);
   SetQuality(95);
}
