/*
DESCRIPCION  : un guerrero-coronel del ejercito orco
FICHERO      : soldado/guerrero-coronel.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include "../std/soldado.h"
inherit AK_SOLDADO;

create()
{
  ::create();
  ::ValoresPorDefecto();
  grado=SO_GRADO_CORONEL;
  clase=SO_CLASE_GUERRERO;
}

