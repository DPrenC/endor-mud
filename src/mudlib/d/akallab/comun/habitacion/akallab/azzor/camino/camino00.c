/*
DESCRIPCION  : Camino
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino00.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino entre Narad y el bosque de Talek");
  SetIntLong(
    "Observas como al este de aqui, el Camino del Este llega al pueblo de Narad, una\n"
    "pequenya villa en la parte alta de este valle. Hacia el oeste, el Camino se\n"
    "adentra en el gran y denso bosque de Talek. Sopla una ligera brisa desde el sur.\n");

  AddDetail(({"pueblo","villa","Narad"}),"Narad es el pueblo que ves al este de aqui.\n");

  AddDetail(({"bosque","bosque de Talek"}),
    "Es un inmenso bosque que se extiende en la parte suroeste del valle de Azzor,\n"
    "hasta el mismo pie de las montanyas. Es un bosque denso y algo sombrio.\n"
    "El Camino del Este lo atraviesa de este a oeste.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
    "Es un importante camino que comunica el valle de Zarkam con los territorios del\n"
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Sopla una suave brisa desde el sur.\n");
 SetIntSmell("Hueles el fresco aroma del campo.\n");
 SetLocate("valle de Azzor");
 SetIndoors(0);

 AddExit("oeste",BOSQUE_TALEK("camino10"));
 AddExit("este",NARAD("calle00"));
}
