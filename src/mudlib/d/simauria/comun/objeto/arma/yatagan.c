/*
  yatagan.c
  (c) Nemesis@Simauria

  Otra de mis armas favoritas: el yatagán
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_ACERO);
   SetShort("un yatagán");
   SetLong("Una espada curva con la hoja muy afilada.\n");
   AddId(({"yatagán","espada","yatagan"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(85);
}
