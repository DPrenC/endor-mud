/***************************************************************************************
 ARCHIVO:	casco.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Casco de los Patrulleros de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_CASCO,1,P_SIZE_LARGE,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"casco","casco de acero"}));
  SetShort("un casco de acero");
  SetLong("Es un resistente casco de acero que usan los patrulleros en Koek.\n");
}