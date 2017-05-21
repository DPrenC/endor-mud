/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	La túnica de los discípulos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,2,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","túnica"}));
  SetShort("una túnica amarilla");
  SetLong(W("Es una túnica amarilla con ribetes azules característica de los "
  	"discípulos del templo de Seri-Solderteg.\n"));
}
