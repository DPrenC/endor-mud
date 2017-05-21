/*
  plombee.c
  (c) Nemesis@Simauria

  Un plombee (maza lastrada con plomo)
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_NINGUNO);
   SetShort("un plombee");
   SetLong("Una pesada maza lastrada con plomo.\n");
   AddId(({"plombee","mazo"}));
   SetMaterial("plomo");
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(90);
}
