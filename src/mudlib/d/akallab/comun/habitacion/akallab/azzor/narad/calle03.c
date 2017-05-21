/*
DESCRIPCION  : Calle de Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle03.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("la calle del pueblo de Narad");
  SetIntLong(
    "Esta calle secundaria acaba aqui junto al templo del pueblo. El templo es una "
    "baja construccion de piedra que se halla al sur de aqui y que posiblemente "
    "este dedicado a algun dios local. Al este de aqui una vieja verja de metal "
    "permite acceder al cementerio del pueblo.\n");

  AddDetail(({"cementerio","verja","muro"}),
    "El cementerio del pueblo se halla al este de aqui. Esta rodeado por un muro "
    "de piedra y una vieja verja de metal es la puerta que permite acceder a el.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el suroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

 SetIntNoise("Este es un lugar tranquilo. No escuchas nada de interes.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("oeste",NARAD("calle02"));
 AddExit("este",NARAD("cement00"));
 AddExit("sur",NARAD("templo"));
}
