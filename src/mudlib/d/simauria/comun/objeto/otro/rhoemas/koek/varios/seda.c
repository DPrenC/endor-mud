/***************************************************************************************
 ARCHIVO:	seda.c
 AUTOR:		[z] Zomax
 FECHA:		24-04-2003
 COMENTARIOS:	Un trozo de seda para hacer ropa.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort("un gran retal de seda élfica");
  SetLong(W("Es un gran retal de seda blanca de una calidad excepcional. Tiene algún que "
  	"otro reglejo y es más suave que una ovejita recién lavada.\n"));
  SetIds(({"seda","seda elfica","seda élfica","retal"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_MEDIUM);
  SetWeight(500);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
