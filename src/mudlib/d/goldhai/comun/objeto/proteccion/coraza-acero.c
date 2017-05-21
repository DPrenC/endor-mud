/*
    Coraza de acero
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
 SetStandard(AT_ARMOUR, 15, P_SIZE_MEDIUM, M_ACERO);
  SetShort("Una coraza de acero");
  SetLong("Es una coraza de acero, típica de Glucksfall.\n");
  SetIds(({"coraza", "coraza de acero"}));
  Set(P_GENDER, GENDER_FEMALE);
}
