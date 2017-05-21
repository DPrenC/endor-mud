/***************************************************************************************
 ARCHIVO:	escudo.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Un escudo ovalado
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_ESCUDO,4,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"escudo"}));
  SetShort("un escudo ovalado");
  SetLong("Es un escudo de acero ovalado muy resistente.\n");
}