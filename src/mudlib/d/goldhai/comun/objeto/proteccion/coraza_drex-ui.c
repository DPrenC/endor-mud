/*
    Coraza de Comodo
    Maler, 15-02-02
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;


create()
{
  ::create();
  SetStandard(AT_ARMOUR, 20, P_SIZE_MEDIUM, M_MITHRIL);
  SetShort("la coraza de Drex-Ui");
  SetLong("Es una coraza de mithril, robada por Drex-Ui hace mucho tiempo.\n");
  AddId( ({ "coraza",
         }) );
  AddAdjective( ({ "de mithril",
                   "de drex",
                   "de drex-ui",
              }) );
  Set(P_GENDER, GENDER_FEMALE);
}
