/*
DESCRIPCION  : Cementerio
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/cement01.c
MODIFICACION : 18-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("el cementerio del pueblo de Gaddaro");
  SetIntLong(
  "Estas en el extremo oeste del cementerio rodeado por decenas de silenciosas "
  "tumbas. Esta parte del cementerio esta algo mas descuidada que el resto y "
  "en algunos sitios incluso crece algo de vegetación.\n");

  AddDetail(({"tumbas","lápidas"}),
    "Las hay por todas partes. Esto es un cementerio.\n");

  AddDetail(({"cementerio","verja","muro"}),
  "El cementerio del pueblo esta rodeado por un muro de piedra y una vieja "
  "verja de metal es la puerta que permite acceder a el.\n");

#include "geografia.ic"
#include "ambiente.ic"

 SetIntNoise("Este es un lugar muy tranquilo.\n");
 SetIntSmell("No huele a nada en especial.\n");

 AddExit("este",GADDARO("cement00"));
}
