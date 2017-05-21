inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_ESCUDO, 2, P_SIZE_GENERIC, M_CUERO);
  SetAds(({"un", "ligero"}));
  AddId(({"armadura","escudo","pelta"}));
  SetShort("un pelta");
  SetLong(
"Es un ligero escudo ovalado hecho de cuero. Est� decorado con diversos\n\
motivos geom�tricos en negro.\n");
  SetResetQuality(95);
  }