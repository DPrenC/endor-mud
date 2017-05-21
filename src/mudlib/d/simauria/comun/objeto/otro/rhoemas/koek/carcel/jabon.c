/***************************************************************************************
 ARCHIVO:	jabon.c
 AUTOR:		[z] Zomax
 FECHA:		02-12-2001
 COMENTARIOS:	Una pastilla de jabón para la cárcel... jisjis...
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una pastilla de jabón");
  SetLong("Es una pastilla de jabón de lo más normal.\n");
  SetIds(({"jabon","jabón","pastilla","pastilla de jabón","pastilla de jabón"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(250);
  SetValue(500);
}
