/*
DESCRIPCION   : Unas botas de metal pequeñas
FICHERO       : botas_metal_p.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create()
{
  ::create();
 SetStandard(AT_BOTAS, 2, P_SIZE_SMALL, M_HIERRO);
  SetShort("unas botas de hierro");
  SetLong("Son un par de botas de cuero cubiertas con láminas de hierro.\n");
  SetIds(({"botas", "botas de hierro"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER, NUMBER_PLURAL);
  SetValue(QueryValue()*4); // Cuadruplico Valor

}
