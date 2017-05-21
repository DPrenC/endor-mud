/***************************************************************************************
 ARCHIVO:	anillo_verde.c
 AUTOR:		[k] Korsario
 FECHA:		10-09-1998
 COMENTARIOS:	El anillo verde de la salvación
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_ANILLO,0,P_SIZE_GENERIC,M_ORO);
  SetIds(({"anillo","anillo salvacion","anillo verde"}));
  SetAds(({"verde"}));
  Set(P_NOSELL,1);

  SetShort("un anillo verde");
  SetLong("Ves un anillo verde. Es bastante sencillo, y totalmente liso. "
  	"Está hecho de un material muy duro y muy hermoso.\n");
}
