inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_GREBAS, 2, P_SIZE_GENERIC, M_ACERO);
  SetAds(({"unas", "brillantes"}));
  AddId(({"armadura","grebas"}));
  SetShort("unas grebas");
  SetLong("Son unas grebas de acero diseñadas para proteger las piernas.\n");
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER, NUMBER_PLURAL);
  }