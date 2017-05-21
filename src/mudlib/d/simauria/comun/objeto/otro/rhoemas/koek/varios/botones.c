/***************************************************************************************
 ARCHIVO:	botones.c
 AUTOR:		[z] Zomax
 FECHA:		24-04-2003
 COMENTARIOS:	Unos bonitos botones de mithril.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort("unos botones de mithril");
  SetLong(W("Son unos preciosos botones forjados de mithril al más puro estilo tradicional "
 	"enano.\n"));
  SetIds(({"botones","botones de mithril"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(50);
  SetValue(1000);
}
