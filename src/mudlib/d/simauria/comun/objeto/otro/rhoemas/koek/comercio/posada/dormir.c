/***************************************************************************************
 ARCHIVO:	dormi.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Un vale para dormir
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un vale para dormir");
  SetLong("Es un vale para dormir unas horas en 'La Posada de Seri'.\n");
  SetIds(({"vale","vale para dormir"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(10);
  SetValue(1600);
  SetMaterial("papel");
}
