/*
DESCRIPCION  : Calle de Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle05.c
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
    "Te encuentras a la entrada del pequenyo pueblo de Narad. Oyes el ruido del "
    "trabajo en la herreria que queda al este de aqui. Al oeste se encuentra la "
    "destileria del pueblo, donde se fabrican bebidas. La cerveza y el vino de "
    "esta zona son bien conocidos en la region. "
    "El Camino del Este continua hacia el norte dejando atras el pueblo.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el suroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
    "Es un importante camino que comunica el valle de Zarkam con los territorios del "
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Oyes el ruido del trabajo en la herreria.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("norte",AZ_CAMINO("camino01"));
 AddExit("este",NARAD("herreria"));
 AddExit("oeste",NARAD("destil00"));
 AddExit("sur",NARAD("calle04"));
}
