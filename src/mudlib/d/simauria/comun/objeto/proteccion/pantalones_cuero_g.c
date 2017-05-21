/*
DESCRIPCION   : pantalones de cuero grandes
FICHERO       : pantalones_cuero_g.c
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
 SetStandard(AT_PANTALONES, 2, P_SIZE_LARGE, M_CUERO);
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetShort("unos pantalones de cuero");
  SetLong("Son unos pantalones de cuero que te protegerán un poco.\n");
  SetIds(({"pantalones", "pantalones de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}