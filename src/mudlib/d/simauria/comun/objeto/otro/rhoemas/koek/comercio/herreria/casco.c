/***************************************************************************************
 ARCHIVO:	casco.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Un casco de acero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_CASCO,2,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"casco","casco de acero"}));
  SetShort("un casco");
  SetLong("Es un resistente casco de acero.\n");
}