/***************************************************************************************
 ARCHIVO:	pantalon.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Un pantalón
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_PANTALONES,1,P_SIZE_SMALL,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"pantalones"}));
  SetAds(({"de cuero"}));

  SetShort("unos pantalones de cuero");
  SetLong("Son unos pantalones de cuero muy bonitos. Están hechos de cuero "
  	"negro, y parecen bastante resistentes, asi como elegantes.\n");
}
