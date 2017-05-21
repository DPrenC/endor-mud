/***************************************************************************************
 ARCHIVO:	plata.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Un poco de plata. (Premio del concurso de pesca)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un trozo de plata");
  SetLong("Es un trozo de plata, brillante y de buena calidad.\n");
  SetIds(({"plata","trozo de plata"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(250);
  SetValue(25000);
}
