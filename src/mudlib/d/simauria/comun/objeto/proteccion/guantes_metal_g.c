/*
DESCRIPCION   : guantes de metal grandes
FICHERO       : guantes_metal_g.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/
#include <properties.h>
#include <combat.h>
#include <materials.h>


inherit ARMOUR;

create()
{
  ::create();
 SetStandard(AT_GUANTES, 3, P_SIZE_LARGE, M_HIERRO);
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetShort("unos guantes de hierro");
  SetLong("Son unos pesados guantes de hierro.\n");
  SetIds(({"guantes", "guantes de hierro"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}
