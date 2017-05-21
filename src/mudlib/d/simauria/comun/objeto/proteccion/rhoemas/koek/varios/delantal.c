/***************************************************************************************
 ARCHIVO:	delantal.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Un delantal (para los tenderos)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TABARDO,1,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"delantal"}));
  SetShort("un delantal");
  SetLong("Es un delantal blanco para no mancharse mucho.\n");
}