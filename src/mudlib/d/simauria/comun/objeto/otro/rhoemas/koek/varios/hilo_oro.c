/***************************************************************************************
 ARCHIVO:	hilo_oro.c
 AUTOR:		[z] Zomax
 FECHA:		24-04-2003
 COMENTARIOS:	Un largo hilo de oro finísimo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort("un fino hilo de oro");
  SetLong(W("Ves un largo hilo de oro, el más fino que has visto en tu vida. Parece "
 	"mentira que alguien haya podido doblegar así el oro, más bien dirías que es "
 	"cosa de magia.\n"));
  SetIds(({"hilo","hilo de oro","fino hilo de oro"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(2);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
