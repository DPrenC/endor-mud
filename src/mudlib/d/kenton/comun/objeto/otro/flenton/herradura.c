/***************************************************************************************
 ARCHIVO:	herradura.c
 AUTOR:		[z] Zomax
 FECHA:		21-01-2002
 COMENTARIOS:	Una herradura para la herreria.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(100);
  SetWeight(600);
  SetIds(({"herradura","herradura de caballo","herradura de la suerte"}));

  SetShort("una herradura");
  SetLong("Es una herradura de caballo. Dicen que da suerte, pero tú no le ves "
  	"mucha utilidad.\n");
}
