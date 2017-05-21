/***************************************************************************************
 ARCHIVO:	anillo_azul.c
 AUTOR:		[k] Korsario
 FECHA:		10-09-1998
 COMENTARIOS:	El anillo az�l de la orientaci�n
 ***************************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>
#include <moving.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_ANILLO,0,P_SIZE_GENERIC,M_ORO);
  SetIds(({"anillo","anillo orientacion","anillo azul","anillo az�l"}));
  SetAds(({"az�l"}));
  Set(P_NOSELL,1);

  SetShort("un anillo az�l");
  SetLong("Ves un anillo az�l. Es bastante sencillo, y totalmente liso. "
  	"Est� hecho de un material muy duro y muy hermoso.\n");
}
