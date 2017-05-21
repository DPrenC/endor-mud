/*
DESCRIPCION   : guantes de metal pequeños
FICHERO       : guantes_metal_p.c
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
 SetStandard(AT_GUANTES, 3, P_SIZE_SMALL, M_HIERRO);
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetShort("unos guantes de hierro");
  SetLong("Son unos pesados guantes de hierro.\n");
  SetIds(({"guantes", "guantes de hierro"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}
