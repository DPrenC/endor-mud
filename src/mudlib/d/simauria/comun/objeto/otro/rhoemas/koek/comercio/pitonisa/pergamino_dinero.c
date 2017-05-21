/***************************************************************************************
 ARCHIVO:	pergamino_dinero.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Un pergamino que usa Fowla para leer la buenaventura sobre el dinero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("pergamino del dinero");
  SetLong(W("Este es un pergamino que predice todo lo relacionado con el dinero "
  	"de las personas que lo llevan. Sólo puede ser usado por su creadora, la "
  	"pitonisa Fowla de Koek. Si lo llevas ella te predecirá tu suerte.\n"));
  SetIds(({"pergamino","pergamino del dinero"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(500);
}
