/***************************************************************************************
 ARCHIVO:	cobre.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Un poco de cobre. (Premio del concurso de pesca)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un trozo de cobre");
  SetLong("Es un trozo de cobre, brillante, rojizo y de buena calidad.\n");
  SetIds(({"cobre","trozo de cobre"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(250);
  SetValue(2500);
}
