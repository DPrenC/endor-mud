/***************************************************************************************
 ARCHIVO:	anillo_azul.c
 AUTOR:		[k] Korsario
 FECHA:		10-09-1998
 COMENTARIOS:	El anillo azúl de la orientación
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
  SetIds(({"anillo","anillo orientacion","anillo azul","anillo azúl"}));
  SetAds(({"azúl"}));
  Set(P_NOSELL,1);

  SetShort("un anillo azúl");
  SetLong("Ves un anillo azúl. Es bastante sencillo, y totalmente liso. "
  	"Está hecho de un material muy duro y muy hermoso.\n");
}
