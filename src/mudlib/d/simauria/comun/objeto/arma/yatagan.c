/*
  yatagan.c
  (c) Nemesis@Simauria

  Otra de mis armas favoritas: el yatag�n
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_ACERO);
   SetShort("un yatag�n");
   SetLong("Una espada curva con la hoja muy afilada.\n");
   AddId(({"yatag�n","espada","yatagan"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(85);
}
