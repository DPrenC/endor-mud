/***************************************************************************************
 ARCHIVO:	sandalias.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Las sandalias del adalid
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
  SetIds(({"sandalias"}));
  SetShort("unas sandalias");
  SetLong("Son unas sandalias de cuero del adalid del templo de Seri-Solderteg.\n");
}
