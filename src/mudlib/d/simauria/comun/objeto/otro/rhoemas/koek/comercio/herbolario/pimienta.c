/***************************************************************************************
 ARCHIVO:	pimienta.c
 AUTOR:		[z] Zomax
 FECHA:		27-04-2003
 COMENTARIOS:	Pimienta roja en polvo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("pimienta roja");
  SetLong(W("Es un puñado de pimienta de color rojo intenso finamente molida, una "
  	"especia muy rara y codiciada.\n"));
  SetIds(({"pimienta","pimienta roja"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(5);
  SetValue(5000);
}
