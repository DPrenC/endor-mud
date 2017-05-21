#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "El sendero continua aqui haciendo una esquina. Hacia el norte, a no demasiada distancia dirias que se ven mausoleos de antiguas familias, hacia el este regresa el sendero... la bruma no te deja ver bien de todas maneras pero jurarias que algo se ha movido y no lo has visto...te estaran jugando tus ojos una mala pasada?\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor cada vez se hace mas fuerte en cuanto te adentras en el cementerio... no hay duda... huele a muertos... a muchos...\n"
    );
  SetIntNoise(
    "Tu imaginacion te esta gastando una mala pasada... porque dirias que escuchas pasos...como de algo que se arrastra entre la niebla.\n"
    );
  AddDetail(({"niebla","bruma"}),
    "Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
    "el cementerio, el resto se trata de una niebla mucho menos densa pero que aun\n"
    "así te impide ver el final del camino.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño, como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que una lapida ha sido arrancada.\n"
    );
  AddExit("norte","camino2.c");
  AddExit("este","camino4.c");
  SetLocate("cementerio2");
}
