inherit "/std/armour";
#include "path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>

create()
{
  ::create();
 SetStandard(AT_ARMOUR,10, P_SIZE_MEDIUM, M_CUERO);
  SetShort("un traje de cuero negro");
  SetLong(W("Es un traje de cuero negro. "
  "Parece untado con algun tipo de aceite, lo cual te permitira moverte "
  "sin hacer ruido más fácilmente.\n"));
  SetIds( ({"traje", "traje negro", "traje de cuero", "traje de cuero negro"}) );
  Set(P_GENDER, GENDER_MALE);
}
