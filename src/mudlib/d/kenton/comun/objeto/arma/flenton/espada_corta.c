/***************************************************************************************
 ARCHIVO:	espada_corta.c
 AUTOR:		[k] Korsario
 FECHA:		07-11-1997
 COMENTARIOS:	Una espada corta
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_ESPADA,7,P_SIZE_SMALL,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  SetResetQuality(95);
  AddAdjective("pequeña");
  SetIds(({"espada","espada corta"}));

  SetShort("una espada corta");
  SetLong("Ves una espada corta. Es de acero. Su empuñadura parece hecha "
  	"para una mano de pequeño tamaño. Es bastante ligera.\n");
}
