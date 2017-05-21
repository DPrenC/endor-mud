/*
DESCRIPCION   : Cota de cuero
FICHERO       : cota_cuero.c
CREACION      : 08-03-03 [Baldur]
MODIFICACION  :
*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create()
{
  ::create();
 SetStandard(AT_CORAZA, 6, P_SIZE_MEDIUM, M_CUERO);
  SetShort("una cota de cuero");
  SetLong("Es una cota  de cuero, la parte que protege el torso esta hecha\n"
  "de cuero endurecido y el resto es cuero mas blando y flexible.\n");
  SetIds(({"coraza", "coraza de cuero", "cota", "cota de cuero"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER,NUMERO_SINGULAR);
}