/*
DESCRIPCION   : Coraza de cuero grande
FICHERO       : coraza_cuero_g.c
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
 SetStandard(AT_CORAZA, 6, P_SIZE_LARGE, M_CUERO);
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetShort("una coraza de cuero");
  SetLong("Es una coraza de cuero bastante burda.\n");
  SetIds(({"coraza", "coraza de cuero"}));
  Set(P_GENDER, GENDER_FEMALE);
}