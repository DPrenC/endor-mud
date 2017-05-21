/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	La túnica del adalid
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,3,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","túnica"}));
  SetShort("una túnica roja");
  SetLong(W("Es una preciosa túnica roja de seda brillante con bordados de oro que "
  	".\n"));
}
