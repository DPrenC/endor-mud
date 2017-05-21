/***************************************************************************************
 ARCHIVO:	botas.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Botas de los peregrinos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_BOTAS,3,P_SIZE_LARGE,M_CUERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"botas","botas sucias"}));
  SetShort("unas botas sucias");
  SetLong(W("Son unas botas de cuero marrón muy resistentes para largos viajes que "
  	"parece que han llegado casi a su límite. Se ve que las han usado mucho.\n"));
}