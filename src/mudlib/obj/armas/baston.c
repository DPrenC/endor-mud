/* baston.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_CAYADO,4,P_SIZE_GENERIC,M_MADERA);
  SetAds(({"de", "madera"}));
  SetIds(({"baston","bastón", "arma", "palo","vara"}));
  SetShort("un bastón");
  SetLong("Es un sencillo bastón hecho en madera tallada. La parte superior se curva hacia "
  "atrás para poder apoyar el peso del cuerpo sobre él.\n");

}
