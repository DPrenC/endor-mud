/***************************************************************************************
 ARCHIVO:	escudo.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	El escudo de los guardias
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_ESCUDO,4,P_SIZE_GENERIC,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"escudo"}));
  SetShort("un gran escudo");
  SetLong("Es un escudo de cuerpo entero con dibujos en relieve.\n");
  AddSubDetail(({"dibujo","dibujos"}),W("Hay un gran dibujo del escudo de Koek en la "
  	"parte frontal del escudo.\n"));
}