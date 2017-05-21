inherit ARMOUR;

#include <properties.h>
#include <combat.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(AT_AMULETO, 0, P_SIZE_GENERIC, M_NINGUNO);
  SetAds(({"un","vulgar","de la suerte"}));
  AddId(({"armadura","amuleto"}));
  SetShort("un amuleto");
  SetLong(
"Es un amuleto de la suerte. Esta hecho de azabache y tiene forma de grillo\n\
sonriente. Quiza de suerte, o quiza no, pero es horrorosamente feo.\n");
  SetMaterial("azabache");
  SetResetQuality(95);
  }