/*
DESCRIPCION  : un guerrero-teniente del ejercito orco
FICHERO      : soldado/guerrero-teniente.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include "../std/soldado.h"
inherit AK_SOLDADO;

create()
{
  ::create();
  ::ValoresPorDefecto();
  grado=SO_GRADO_TENIENTE;
  clase=SO_CLASE_GUERRERO;
}


