/***************************************************************************************
 ARCHIVO:	pergamino_objeto.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Un pergamino que usa Fowla para encontrar cosas
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("pergamino de objeto");
  SetLong(W("Este es un pergamino de localización de objetos perdidos. Sólo puede ser "
  	"usado por su creadora, la pitonisa Fowla de Koek. Si lo llevas ella te "
  	"encontrará lo que hayas perdido.\n"));
  SetIds(({"pergamino","pergamino de objeto"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(500);
}
