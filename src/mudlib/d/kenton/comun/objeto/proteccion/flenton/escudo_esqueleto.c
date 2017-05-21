/***************************************************************************************
 ARCHIVO:	escudo_esqueleto.c
 AUTOR:		[z] Zomax
 FECHA:		25-01-2002
 COMENTARIOS:	El escudo de un esqueleto.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_ESCUDO,3,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"escudo","escudo viejo"}));

  SetShort("un escudo viejo");
  SetLong("Es un escudo viejo de acero que en su dia perteneció a un gran guerrero.\n");
}
