/*
DESCRIPCION  : Calle de Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle04.c
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
    "La calle principal del pueblo alcanza aqui el extremo norte de la plaza y, tras "
    "atravesarla, continua hacia el oeste. Al oeste de aqui observas el ayuntamiento "
    "del poblado y al este una casa particular.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el suroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
    "Es un importante camino que comunica el valle de Zarkam con los territorios del "
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Oyes el ajetreo de la fonda.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("oeste",NARAD("ayto"));
 AddExit("este",NARAD("casa01"));
 AddExit("suroeste",NARAD("calle01"));
 AddExit("norte",NARAD("calle05"));
 AddExit("sur",NARAD("calle02"));
}
