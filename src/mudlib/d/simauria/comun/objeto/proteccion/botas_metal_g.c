/*
DESCRIPCION   : Unas botas de metal grandes
FICHERO       : botas_metal_g.c
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
 SetStandard(AT_BOTAS, 2, P_SIZE_LARGE, M_HIERRO);
  SetShort("unas botas de hierro");
  SetLong("Son un par de botas de cuero cubiertas con láminas de hierro.\n");
  SetIds(({"botas", "botas de hierro"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER, NUMBER_PLURAL);
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

}
