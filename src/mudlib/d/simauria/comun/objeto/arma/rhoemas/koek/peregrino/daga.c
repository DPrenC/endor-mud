/***************************************************************************************
 ARCHIVO:	daga.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Daga para los peregrinos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO,5,P_SIZE_MEDIUM,M_HIERRO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"daga","peque�a daga","pequenya daga"}));
  SetShort("una peque�a daga");
  SetLong(W("Es una daga peque�a pero muy afilada que sirve tanto como para cortar "
  	"cualquier tipo de comida como para defenderse de los desalmados.\n"));
}