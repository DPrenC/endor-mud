/***************************************************************************************
 ARCHIVO:	escudo.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	El escudo de los patrulleros
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_ESCUDO,3,P_SIZE_LARGE,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"escudo"}));
  SetShort("un escudo");
  SetLong("Es un escudo mediano con dibujos en relieve.\n");
  AddSubDetail(({"dibujo","dibujos"}),W("Hay un gran dibujo del escudo de Koek en la "
  	"parte frontal del escudo.\n"));
}