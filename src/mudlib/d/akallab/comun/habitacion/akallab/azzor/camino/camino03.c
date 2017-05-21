/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino03.c
MODIFICACION : 05-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino del Este");
  SetIntLong(
    "La pendiente del Camino del Este se modera a medida que te acercas al río\n"
    "Kuneii. Al oeste del camino puedes observar una amplia extension de vinyedos,\n"
    "y mas alla, el inmenso bosque de Talek. Los vinyedos pertenecen a la villa de\n"
    "Norad que se halla al suroeste del valle.\n");

  AddDetail(({"vinyedos","viñedos"}),
    "Las tierras que van desde el camino hasta las proximidades del bosque de Talek\n"
    "al oeste, y hasta el río al norte, pertenecen a la villa de Norad. Se dedican\n"
    "al cultivo de la vinya, cuya uva se emplea luego en la elaboracion de un\n"
    "conocido vino.\n");

  AddDetail(({"pueblo","villa","Narad"}),"Narad es el pueblo que ves al suroeste.\n");

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

 AddExit("norte",AZ_CAMINO("camino04"));
 AddExit("sur",AZ_CAMINO("camino02"));
}
