inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_CAPUCHA, 2, P_SIZE_GENERIC, M_ACERO);
  SetAds(({"una","ligera", "de malla"}));
  SetIds(({"armadura","casco","capellina"}));
  SetShort("una capellina de malla");
  SetLong(
"Es una simple capucha compuesta de aros metálicos unidos entre sí,\n\
que cubre la cabeza y parte de los hombros.\n");
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(95);
  }