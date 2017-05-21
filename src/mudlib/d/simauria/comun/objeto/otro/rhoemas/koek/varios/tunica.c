/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Una túnica.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <materials.h>
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,1,P_SIZE_MEDIUM,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","túnica","tunica ceremonial","túnica ceremonial","túnica púrpura"}));
  SetShort("una túnica ceremonial púrpura");
  SetLong(W("Es una preciosa túnica de color púrpura intenso con bordados en los puños y un bonito "
  	"escudo en el pecho.\n"));
}
