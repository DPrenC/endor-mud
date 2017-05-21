/*
  garfio.c
  (c) Nemesis@Simauria

  Un garfio como el que debe llevar
  cualquier pirata que se precie.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MANOPLA, 4, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un garfio");
   SetLong("Parece un gancho de carnicero, pero se engancha a la mano. "
           "Sin duda fue útil para algún pirata, aunque ahora está algo oxidado.\n");
   AddId(({"garfio","gancho", "garfio pirata"}));
   Set(P_GENDER,GENERO_MASCULINO);
   SetResetQuality(80);
   SetQuality(75);
}
