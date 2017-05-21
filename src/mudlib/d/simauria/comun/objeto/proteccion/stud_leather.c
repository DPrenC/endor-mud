// Armadura de cuero endurecido para los guardias de Nandor

inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_CORAZA, 5, P_SIZE_LARGE, M_CUERO);
  SetAds(({"una","pesada"}));
  AddId(({"armadura","armadura de cuero","armadura de cuero endurecido"}));
  SetShort("una armadura de cuero endurecido");
  SetLong(
"Es una armadura de cuero endurecido de buena factura. Está decorada con\n\
dibujos macabros y sangrientos.\n");
  SetResetQuality(95);
  }