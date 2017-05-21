/***************************************************************************************
 ARCHIVO:	cubo.c
 AUTOR:		[z] Zomax
 FECHA:		21-01-2002
 COMENTARIOS:	Un cubo para vender en la herreria.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(150);
  SetWeight(1000);
  SetIds(({"cubo","cubo de metal"}));

  SetShort("un cubo de metal");
  SetLong("Es un cubo de metal, de los que se usa para recoger agua del pozo.\n");
}
