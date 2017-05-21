/*
DESCRIPCION  : un soldado-guardia del ejercito orco
FICHERO      : soldado/soldado_guardia.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include "../std/soldado.h"
inherit AK_SOLDADO;

create()
{
  ::create();
  ::ValoresPorDefecto();
  grado=SO_GRADO_SOLDADO;
  clase=SO_CLASE_GUARDIA;
  queProtege="este lugar";
}

