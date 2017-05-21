/*
DESCRIPCION   : guantes de cuero grandes
FICHERO       : guantes_cuero_g.c
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
 SetStandard(AT_GUANTES, 1, P_SIZE_LARGE, M_CUERO);
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetShort("unos guantes de piel");
  SetLong(W("Son unos bonitos guantes de piel, que obviamente no te "
	"proteger�n de ning�n golpe, pero te dar�n ese toque de "
	"distinci�n que mucha gente desea...\n"));
  SetIds(({"guantes", "guantes de piel"}));
  Set(P_NUMBER, NUMBER_PLURAL);
}
