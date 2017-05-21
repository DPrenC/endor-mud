/***************************************************************************************
 ARCHIVO:	banyo.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Un vale para un banyo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un vale para un baño");
  SetLong("Es un vale para un baño en 'La Posada de Seri'.\n");
  SetIds(({"vale","vale para banyo","vale para baño"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(10);
  SetValue(1500);
  SetMaterial("papel");
}
