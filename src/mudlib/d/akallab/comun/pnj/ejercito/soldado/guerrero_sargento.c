/*
DESCRIPCION  : un guerrero-sargento del ejercito orco
FICHERO      : soldado/guerrero_sargento.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include "../std/soldado.h"
inherit AK_SOLDADO;

create()
{
  ::create();
  ::ValoresPorDefecto();
  grado=SO_GRADO_SARGENTO;
  clase=SO_CLASE_GUERRERO;
}

