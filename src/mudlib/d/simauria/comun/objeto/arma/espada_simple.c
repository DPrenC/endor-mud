/*
  espada_simple.c
  (c) Nemesis@Simauria

  Una simple espada.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
  SetStandard(WT_ESPADA, 2, P_SIZE_GENERIC, M_HIERRO);
  SetShort("una vieja espada");
  SetLong("Es una vieja espada corta de hoja recta.\n");
  AddId(({"espada","espada corta"}));
  SetResetQuality(80);
  SetQuality(80);
}
