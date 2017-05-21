/*
  mangual_pesado.c
  (c) Nemesis@Simauria

  Un mangual pesado que hace pupita...
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MANGUAL, 10, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un mangual pesado");
   SetLong("Es un pesado mangual.\n");
   AddId(({"mangual"}));
   SetNumberHands(2);
   SetResetQuality(80);
}
