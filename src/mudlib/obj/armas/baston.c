/* baston.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_CAYADO,4,P_SIZE_GENERIC,M_MADERA);
  SetAds(({"de", "madera"}));
  SetIds(({"baston","bast�n", "arma", "palo","vara"}));
  SetShort("un bast�n");
  SetLong("Es un sencillo bast�n hecho en madera tallada. La parte superior se curva hacia "
  "atr�s para poder apoyar el peso del cuerpo sobre �l.\n");

}
