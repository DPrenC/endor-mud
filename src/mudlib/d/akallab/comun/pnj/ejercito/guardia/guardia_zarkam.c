/*
DESCRIPCION  : un guardia de Zarkam
FICHERO      : soldado/soldado_guardia_Zarkam.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include "../std/soldado.h"
inherit AK_SOLDADO;

create()
{
  ::create();

  ::ValoresPorDefecto();
  switch(random(100))
  	{
	case 0..40: grado=SO_GRADO_SOLDADO; break;
	case 41..80: grado=SO_GRADO_SARGENTO; break;
	case 81..100: grado=SO_GRADO_CAPITAN; break;
	}
  clase=SO_CLASE_GUARDIA;
  queProtege="la ciudad de Zarkam";
}

