/*
  kriss.c
  (c) Nemesis@Simauria

  Un kriss. Y no, no es el cuchillo de Dune.
  Es un cuchillo malayo con la hoja ondulada.
  Y es que el tal Herbert cogió cosas de sitios
  insospechados...
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_CUCHILLO, 3, P_SIZE_GENERIC, M_ACERO);
   SetShort("un kriss");
   SetLong("Un cuchillo de hoja larga y ondulada.\n");
   AddId(({"kriss","cuchillo"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(90);
   SetQuality(85);
}
