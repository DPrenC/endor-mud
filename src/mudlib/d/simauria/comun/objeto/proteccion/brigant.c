inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_CORAZA, 7, P_SIZE_GENERIC, M_HIERRO);
  SetAds(({"una","pesada"}));
  AddId(({"armadura","brigantina"}));
  SetShort("una brigantina");
  SetLong(
"Es un ropón de lona al que están enganchadas varias placas metálicas,\n\
sobre las que se ha cosido una tela de color azul.\n");
  SetResetQuality(95);
  }