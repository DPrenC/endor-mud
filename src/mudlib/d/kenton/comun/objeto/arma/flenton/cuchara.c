/***************************************************************************************
 ARCHIVO:	cuchara.c
 AUTOR:		[a] Ares
 FECHA:		07-11-1997
 COMENTARIOS:	Cuchara anti-fantasmas kender
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_CUCHILLO,1,P_SIZE_SMALL,M_PLATA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  Set(P_NOSELL,1);
  SetWeight(2);
  AddAdjective("pequeña");
  SetIds(({"cuchara","cucharilla"}));

  SetShort("una pequeña cucharilla");
  SetLong("Es una pequeña cucharilla de plata, manchada en su parte "
  	"superior por una sustancia rojiza.\n");
}
