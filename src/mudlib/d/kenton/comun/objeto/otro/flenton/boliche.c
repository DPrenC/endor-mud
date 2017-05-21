/***************************************************************************************
 ARCHIVO:	boliche.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Un boliche de cristal azúl
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"boliche"}));
  SetValue(50);
  SetWeight(5);

  SetShort("un boliche");
  SetLong("Es un boliche de cristal azúl.\n");
}
