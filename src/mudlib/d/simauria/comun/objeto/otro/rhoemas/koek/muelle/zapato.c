/***************************************************************************************
 ARCHIVO:	zapato.c
 AUTOR:		[z] Zomax
 FECHA:		02-03-2003
 COMENTARIOS:	Un zapato ajado.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_BOTAS,1,P_SIZE_MEDIUM,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"zapato","zapato viejo"}));
  SetShort("un zapato viejo");
  SetLong(W("Es un trozo de cuero ajado lleno de moho y algas que parece haber salido "
  	"del fondo del mar. Parece más viejo que el mismísimo Asthar.\n"));
}