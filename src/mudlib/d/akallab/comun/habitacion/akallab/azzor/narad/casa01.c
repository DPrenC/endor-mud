/*
DESCRIPCION  : Casa particular
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/casa01.c
MODIFICACION : 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("una casa del pueblo de Narad");
  SetIntLong(
  "Estas en el interior de una casa particular. Es una construccion no muy "
    "grande hecha con gruesos troncos de madera a la que se ha adosado una "
    "chimenea de piedra. Es austera, sin apenas decoracion alguna, pero "
    "resulta acogedora. Junto a la chimenea se halla un banco de madera "
    "donde sentarse al abrigo del calor de la lumbre.\n");

  AddDetail(({"banco"}),
  "Es un largo banco de madera donde sentarse. Esta colocado junto a la "
    "chimenea de la casa donde arde un agradable fuego.\n");

  AddDetail(({"chimenea"}),
  "La chimenea de piedra esta adosada a la casa. En ella arde un "
    "agradable fuego que calienta el ambiente.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el noroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

 SetIntNoise("Oyes el fuego crepitar en la chimenea.\n");
 SetIntSmell("Hueles el olor que desprende la madera al quemarse.\n");
 SetLocate("villa de Narad");
 SetIndoors(1);
 SetIntBright(50);

 AddExit("oeste",NARAD("calle04"));
}
