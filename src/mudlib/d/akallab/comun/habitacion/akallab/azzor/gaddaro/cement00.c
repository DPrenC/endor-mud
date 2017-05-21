/*
DESCRIPCION  : Cementerio
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/cement00.c
MODIFICACION : 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("el cementerio del pueblo de Gaddaro");
  SetIntLong(
  "Te encuentras en el cementerio del pueblo. A tu alrededor puedes observar "
  "decenas de tumbas de los que alguna vez fueron habitantes de este pueblo. "
  "Muchas lápidas de piedra están rotas o descuidadas. Al sur de "
  "aqu una vieja verja de metal permite salir del cementerio.\n");

  AddDetail(({"tumbas","lápidas","lapidas"}),
    "Las hay por todas partes. Esto es un cementerio.\n");

  AddDetail(({"cementerio","verja","muro"}),
  "El cementerio del pueblo esta rodeado por un muro de piedra y una vieja "
  "verja de metal es la puerta que permite acceder a el.\n");

#include "geografia.ic"
#include "ambiente.ic"

 SetIntNoise("Este es un lugar muy tranquilo.\n");
 SetIntSmell("No huele a nada en especial.\n");

 AddExit("sur",GADDARO("calle05"));
 AddExit("oeste",GADDARO("cement01"));
}
