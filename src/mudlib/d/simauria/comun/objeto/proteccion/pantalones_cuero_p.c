/*
DESCRIPCION   : pantalones de cuero pequeños
FICHERO       : pantalones_cuero_p.c
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
 SetStandard(AT_PANTALONES, 2, P_SIZE_SMALL, M_CUERO);
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetShort("unos pantalones de cuero");
  SetLong("Son unos pantalones de cuero que te protegerán un poco.\n");
  SetIds(({"pantalones", "pantalones de cuero"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}