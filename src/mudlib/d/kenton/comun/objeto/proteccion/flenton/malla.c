/***************************************************************************************
 ARCHIVO:	jubon.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Un jubón
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_CORAZA,6,P_SIZE_SMALL,M_CUERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"malla"}));
  SetAds(({"una","de cuero"}));

  SetShort("una malla de cuero");
  SetLong("Es una malla de cuero. Ha sido fabricada con el mejor cuero de "
  	"Flenton. Tiene unos adornos muy bonitos.\n");
}
