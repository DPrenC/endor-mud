/***************************************************************************************
 ARCHIVO:	baculo.c
 AUTOR:		[z] Zomax
 FECHA:		29-12-2001
 COMENTARIOS:	El báculo del adalid
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_VARA,5,P_SIZE_MEDIUM,M_MADERA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_CANT_STEAL,1);
  SetIds(({"báculo","baculo"}));
  SetShort("un báculo");
  SetLong(W("Es un báculo largo de madera con una pequeña bola de cristal negro en "
  	"la punta. Parece que es algo más que un palo, pero sin duda el único que sabe "
  	"usarlo es su dueño.\n"));
  AddSubDetail(({"bola","bola de cristal","bola de cristal negro"}),W("Es muy "
  	"extraña. Parece que esté vacia pero jurarías que de vez en cuando se "
  	"ilumina y algo se mueve en su interior.\n"));
}
