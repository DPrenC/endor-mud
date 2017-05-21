/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		29-12-2001
 COMENTARIOS:	La túnica de los aprendices
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,1,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","túnica"}));
  SetShort("una túnica blanca");
  SetLong(W("Es una túnica blanca con ribetes azul pálido característica de los "
  	"aprendices del templo de Seri-Solderteg.\n"));
}
