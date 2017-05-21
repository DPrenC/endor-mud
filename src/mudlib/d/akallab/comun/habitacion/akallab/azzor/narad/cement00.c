/*
DESCRIPCION  : Cementerio
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/cement00.c
MODIFICACION : 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("el cementerio del pueblo de Narad");
  SetIntLong(
  "Te encuentras en el cementerio del pueblo. A tu alrededor puedes observar "
    "decenas de tumbas de los que alguna vez fueron habitantes de este pueblo. "
    "Algunas de las lapidas de piedra estan rotas o descuidadas. Al oeste de "
    "aqui una vieja verja de metal permite salir del cementerio.\n");

  AddDetail(({"tumbas","lapidas"}),
    "Las hay por todas partes. Esto es un cementerio.\n");

  AddDetail(({"cementerio","verja","muro"}),
  "El cementerio del pueblo esta rodeado por un muro de piedra y una vieja "
    "verja de metal es la puerta que permite acceder a el.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el suroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

 SetIntNoise("Este es un lugar muy tranquilo.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("oeste",NARAD("calle03"));
 AddExit("sur",NARAD("cement01"));
}
