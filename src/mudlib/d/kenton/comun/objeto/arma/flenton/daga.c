/***************************************************************************************
 ARCHIVO:	daga.c
 AUTOR:		[k] Korsario
 FECHA:		07-11-1997
 COMENTARIOS:	Una daga
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_CUCHILLO,2,P_SIZE_SMALL,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  SetResetQuality(95);
  AddAdjective("pequeña");
  SetIds(({"daga"}));

  SetShort("una daga");
  SetLong("Una pequeña daga. Es bastante sencilla, sin muchos ornamentos. La "
  	"empuñadura es de color negro y muy suave al tacto.\n");
}
