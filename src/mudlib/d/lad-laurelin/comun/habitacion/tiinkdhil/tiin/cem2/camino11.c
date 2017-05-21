#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Estas cerca de una de las paredes laterales del cementerio, aquí el camino sigue al norte haciendo que te internes un poco mas en este lugar de muerte y al oeste, en un sendero brumoso que no parece nada seguro...\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor cada vez se hace mas fuerte en cuanto te adentras en el cementerio... no hay duda... huele a muertos... a muchos... y en alto estado de descomposicion.\n"
    );
  SetIntNoise(
    "Tu imaginacion te esta gastando una mala pasada... porque dirias que escuchas pasos...como de algo que se arrastra entre la niebla.\n"
    );
  AddDetail(({"niebla","bruma"}),
    "Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
    "el cementerio, el resto se trata de una niebla mucho menos densa pero que aun\n"
    "así te impide ver el final del camino.\n"
    );
  AddExit("oeste","camino9.c");
  AddExit("norte","camino14.c");
  SetLocate("cementerio2");
}
