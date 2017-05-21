/***************************************************************************************
 ARCHIVO:	casco.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Casco de la Guardia de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_CASCO,2,P_SIZE_LARGE,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"casco","casco de gala"}));
  SetShort("un casco de gala");
  SetLong(W("Es un resistente casco de acero, pero no parece como los normales de Koek, "
  	"parece más uno de la guardia.\n"));
}