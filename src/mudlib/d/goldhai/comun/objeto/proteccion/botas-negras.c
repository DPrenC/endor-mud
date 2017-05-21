/*
     Botas negras
     Maler@sim 15-02-02
*/
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create()
{
  ::create();
  SetStandard(AT_BOTAS, 4, P_SIZE_LARGE, M_HIERRO);
  SetShort("las botas negras de Glucksfall");
  SetLong("Son un par de botas de cuero cubiertas con láminas de hierro. "
  "Son las botas que llevan los ciudadanos de la peligrosa ciudad de Glucksfall.\n");
  AddId( ({ "botas",
         }) );
  AddAdjective( ({ "de hierro",
                   "negras",
                   "de glucksfall",
              }) );
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER, NUMBER_PLURAL);
}
