/***************************************************************************************
 ARCHIVO:	botas.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Botas de la Guardia de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_BOTAS,2,P_SIZE_LARGE,M_CUERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"botas","botas negras"}));
  SetShort("unas botas negras");
  SetLong("Son unas botas de cuero negro con hebillas doradas.\n");
  AddSubDetail(({"hebilla","hebillas","hebilla dorada","hebillas doradas"}),W("Las botas "
  	"llevan un par de hebillas doradas muy bonitas.\n"));
}