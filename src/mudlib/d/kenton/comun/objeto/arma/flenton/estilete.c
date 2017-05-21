/***************************************************************************************
 ARCHIVO:	estilete.c
 AUTOR:		[o] Okkita
 FECHA:		07-11-1997
 COMENTARIOS:	Un estilete
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_CUCHILLO,3,P_SIZE_SMALL,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  SetResetQuality(100);
  AddAdjective("pequeña");
  SetIds(({"estilete","daga","larga"}));
  SetAds(({"afilada","larga"}));

  SetShort("un estilete");
  SetLong("Una daga fina y larga. Tiene una hoja estrecha muy afilada, con "
  	"una empuñadura de madera. Es un arma ligera y muy manejable.\n");
}
