/*
DESCRIPCION  : Calle de Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle01.c
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
    "Estas en el extremo oeste de la plaza del pueblo de Narad. La calle principal "
    "continua hacia el oeste y, tras atravesar la plaza, hacia el norte. Al sur de "
    "aqui se encuentra la parada de la diligencia que recorre el valle y al norte "
    "el ayuntamiento del pueblo.\n");

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

 AddExit("oeste",NARAD("calle00"));
 AddExit("este",NARAD("calle02"));
 AddExit("nordeste",NARAD("calle04"));
 AddExit("norte",NARAD("ayto"));
 AddExit("sur",NARAD("diligencia"));
}
