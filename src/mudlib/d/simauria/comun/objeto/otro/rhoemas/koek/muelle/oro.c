/***************************************************************************************
 ARCHIVO:	oro.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Una pepita de oro. (Premio del concurso de pesca)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una pepita de oro");
  SetLong(W("Es una perfecta y brillante pepita de oro, algo por lo que muchos matarían, "
  	"sobre todo enanos.\n"));
  SetIds(({"oro","pepita","pepita de oro"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(250);
  SetValue(250000);
}
