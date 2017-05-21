/*
DESCRIPCION  : Casa particular
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/casa02.c
MODIFICACION : 18-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("una casa del pueblo de Gaddaro");
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

  AddDetail(({"pueblo","villa","Gaddaro"}),
  "Gaddaro es el nombre de este pueblo situado en el noroeste del "
  "valle de Azzor. Sus habitantes se dedican basicamente a la agricultura "
  "y a la pesca en el cercano lago Darum.\n");

 SetIntNoise("Oyes el fuego crepitar en la chimenea.\n");
 SetIntSmell("Hueles el olor que desprende la madera al quemarse.\n");
 SetLocate("pueblo de Gaddaro");
 SetIndoors(1);
 SetIntBright(50);

 AddExit("sur",GADDARO("calle04"));
}
