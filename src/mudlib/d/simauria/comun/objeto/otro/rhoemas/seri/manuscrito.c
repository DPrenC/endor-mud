/***************************************************************************************
 ARCHIVO:	manuscrito.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	El manuscrito perdido del templo de Seri-Solderteg.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un brillante manuscrito");
  SetLong(W("Es un trozo de papel brillante que tiene escrito algo que no entiendes, de "
  	"hecho no te sirve de mucho pero sus reflejos aguamarinos te atraen, queda muy "
  	"decorativo. Quizás encuentres a alguien que le sirva.\n"));
  SetIds(({"manuscrito","brillante manuscrito"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(10);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
