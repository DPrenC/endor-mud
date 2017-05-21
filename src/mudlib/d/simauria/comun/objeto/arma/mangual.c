/*
  mangual.c
  (c) Nemesis@Simauria

  Un mangual ligero.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MANGUAL, 5, P_SIZE_GENERIC, M_ACERO);
   SetShort("un mangual");
   SetLong("Tres pesadas bolas met�licas unidas a un mango met�lico por tres oxidadas cadenas.\n");
   AddId(({"mangual"}));
   SetResetQuality(85);
   SetQuality(75);
}
