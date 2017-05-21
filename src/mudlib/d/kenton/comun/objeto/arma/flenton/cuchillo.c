/***************************************************************************************
 ARCHIVO:	cuchillo.c
 AUTOR:		[k] Korsario
 FECHA:		07-11-1997
 COMENTARIOS:	Un cuchillo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_CUCHILLO,2,P_SIZE_SMALL,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  SetResetQuality(95);
  AddAdjective("peque�o");
  SetIds(({"cuchillo"}));

  SetShort("una daga");
  SetLong("Un peque�o cuchillo. Parece de bastante calidad. Tiene una "
  	"empu�adura de madera.\n");
}
