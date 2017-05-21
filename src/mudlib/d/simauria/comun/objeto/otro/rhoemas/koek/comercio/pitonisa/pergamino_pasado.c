/***************************************************************************************
 ARCHIVO:	pergamino_pasado.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Un pergamino que usa Fowla para leer el pasado
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("pergamino del pasado");
  SetLong(W("Este es un pergamino que lee el pasado de las personas que lo llevan. "
  	"Sólo puede ser usado por su creadora, la pitonisa Fowla de Koek. Si lo "
  	"llevas ella te leerá tu pasado.\n"));
  SetIds(({"pergamino","pergamino del pasado"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(500);
}
