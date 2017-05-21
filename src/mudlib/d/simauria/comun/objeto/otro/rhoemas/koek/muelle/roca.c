/***************************************************************************************
 ARCHIVO:	roca.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Una roca pesada para partir el hielo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una pesada roca");
  SetLong("Es una roca muy muy pesada.\n");
  SetIds(({"roca","roca pesada"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(5000000);
  SetValue(0);
}
