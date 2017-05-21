/***************************************************************************************
 ARCHIVO:	camisa.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Una simple camisa.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,1,P_SIZE_MEDIUM,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"camisa"}));
  SetShort("una camisa blanca");
  SetLong("Es una simple camisa blanca pero muy bien cosida.\n");
}