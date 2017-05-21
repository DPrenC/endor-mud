/***************************************************************************************
 ARCHIVO:	jabon.c
 AUTOR:		[z] Zomax
 FECHA:		02-12-2001
 COMENTARIOS:	Una pastilla de jab�n para la c�rcel... jisjis...
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una pastilla de jab�n");
  SetLong("Es una pastilla de jab�n de lo m�s normal.\n");
  SetIds(({"jabon","jab�n","pastilla","pastilla de jab�n","pastilla de jab�n"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(250);
  SetValue(500);
}
