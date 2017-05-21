/*
  zaghnal.c
  (c) Nemesis@Simauria

  Una de mis armas favoritas: el zaghnal :)
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_HACHA, 11, P_SIZE_GENERIC, M_ACERO);
   SetShort("un zaghnal");
   SetLong("Una poderosa hacha con dos pesadas hojas curvas en forma de cuchillo.\n");
   AddId(({"zaghnal","hacha"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(90);
}
