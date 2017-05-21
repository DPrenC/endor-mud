/***************************************************************************************
 ARCHIVO:	zafiro.c
 AUTOR:		[z] Zomax
 FECHA:		09-04-2003
 COMENTARIOS:	Un zafiro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un zafiro");
  SetLong("Es un bonito zafiro azulado con forma de lágrima y muy bien tallado.\n");
  SetIds(({"zafiro","zafiro lagrima"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(5);
  SetValue(500000);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
