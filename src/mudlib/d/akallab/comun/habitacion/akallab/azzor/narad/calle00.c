/*
DESCRIPCION  : Calle de Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle00.c
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
    "Te encuentras a la entrada del pequenyo pueblo de Narad. Te llega un agradable "
    "olor a comida desde la fonda 'El ciervo salvaje' que se halla justo al sur de "
    "aqui. Resulta muy tentador para tu pobre estomago. Al norte de la calle hay "
    "una casa particular. El Camino del Este continua hacia el oeste dejando atras "
    "el pueblo.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el suroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
    "Es un importante camino que comunica el valle de Zarkam con los territorios del "
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Oyes el ajetreo de la fonda.\n");
 SetIntSmell("Un agradable olor a comida llega desde la fonda.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("oeste",AZ_CAMINO("camino00"));
 AddExit("este",NARAD("calle01"));
 AddExit("sur",NARAD("fonda"));
 AddExit("norte",NARAD("casa00"));
}
