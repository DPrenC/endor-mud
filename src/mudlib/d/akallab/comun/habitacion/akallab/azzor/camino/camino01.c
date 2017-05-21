/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino01.c
MODIFICACION : 05-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino del Este frente a Narad");
  SetIntLong(
    "Observas como al sur de aqui, el Camino del Este llega al pueblo de Narad, una\n"
    "pequenya villa en la parte alta de este valle. Hacia el nordeste, el Camino\n"
    "continua descendiendo lentamente por el valle de Azzor hacia el río Kuneii que\n"
    "ves a lo lejos. Sopla una ligera brisa desde el este.\n");

  AddDetail(({"pueblo","villa","Narad"}),"Narad es el pueblo que ves al sur de aqui.\n");

  AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),
    "El río Kuneii recorre este valle de este a oeste. Es un río caudaloso plagado\n"
    "de rapidos que hacen que no sea navegable. Nace en el vecino valle de Zarkam y\n"
    "a traves de las Cataratas de Nurr atraviesa las Montanyas Negras y entra en\n"
    "este valle. Desemboca al sur de la ciudad de Azzor.\n");

  AddDetail(({"bosque","bosque de Talek"}),
    "Es un inmenso bosque que se extiende en la parte suroeste del valle de Azzor,\n"
    "hasta el mismo pie de las montanyas. Es un bosque denso y algo sombrio.\n"
    "El Camino del Este lo atraviesa de este a oeste.\n");

  AddDetail(({"Camino","camino","camino del este","camino del Este","Camino del Este"}),
    "Es un importante camino que comunica el valle de Zarkam con los territorios del\n"
    "valle de Azzor en la costa este de la peninsula orca de Aguliuk.\n");

 SetIntNoise("Sopla una suave brisa desde el este.\n");
 SetIntSmell("Hueles el fresco aroma del campo.\n");
 SetLocate("valle de Azzor");
 SetIndoors(0);

 AddExit("nordeste",AZ_CAMINO("camino02"));
 AddExit("sur",NARAD("calle05"));
}
