/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Una túnica.
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
  SetIds(({"tunica","túnica"}));
  SetShort("una túnica azul marino");
  SetLong(W("Es una preciosa túnica azul marino con bordados en los puños y un bonito "
  	"escudo en el pecho.\n"));
}