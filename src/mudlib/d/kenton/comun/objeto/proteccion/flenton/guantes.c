/***************************************************************************************
 ARCHIVO:	guantes.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Unos guantes
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_GUANTES,6,P_SIZE_SMALL,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"guantes"}));
  SetAds(({"unos","de cuero"}));

  SetShort("unos guantes de cuero");
  SetLong("Son unos guantes de cuero. Están hechos por un cuero de bastante "
  	"calidad, parecen bastante resistentes. No tienen ningun tipo de adornos.\n");
}
