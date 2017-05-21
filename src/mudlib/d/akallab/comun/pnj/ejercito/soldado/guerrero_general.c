/*
DESCRIPCION  : un guerrero-general del ejercito orco
FICHERO      : soldado/guerrero-general.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include "../std/soldado.h"
inherit AK_SOLDADO;

create()
{
  ::create();
  ::ValoresPorDefecto();
  grado=SO_GRADO_GENERAL;
  clase=SO_CLASE_GUERRERO;
}

