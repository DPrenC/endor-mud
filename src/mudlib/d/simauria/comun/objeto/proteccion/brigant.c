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
"Es un rop�n de lona al que est�n enganchadas varias placas met�licas,\n\
sobre las que se ha cosido una tela de color azul.\n");
  SetResetQuality(95);
  }