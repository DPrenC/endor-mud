/***************************************************************************************
 ARCHIVO:	espada_oxidada.c
 AUTOR:		[k] Krayten
 FECHA:		07-11-1997
 COMENTARIOS:	Una espada oxidada
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_ESPADA,8,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  SetWeight(QueryWeight()+2000);
  SetIds(({"espada","espada oxidada"}));

  SetShort("una espada oxidada");
  SetLong("Su hoja está oxidada aunque su empuñadura indica que en tiempos "
  	"pasados debió de pertener a un gran guerrero.\n");
}
