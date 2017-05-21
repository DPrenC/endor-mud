
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Estas en un sendero que te lleva al interior del cementerio. Las tumbas,\n"
    "desperdigadas aqui y alla sobresalen de entre la niebla, haciendo que el lugar\n"
    "resulte tenebroso y terrorifico. En la distancia puedes distinguir el contorno\n"
    "de unos edificios, pero ahora mismo no sabrias decir bien que aspecto tienen.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor es cada vez mas fuerte... huele... a rancio y a muerte...\n"
    );
  SetIntNoise(
    "Tu imaginación te esta gastando una mala pasada... porque dirias que escuchas pasos...como de algo que se arrastra entre la niebla.\n"
    );
  AddDetail(({"niebla","bruma"}),
    "Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
    "el cementerio, el resto se trata de una niebla mucho menos densa pero que aun\n"
    "así te impide ver el final del camino.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño, como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que una lapida ha sido arrancada.\n"
    );

  AddItem(ALUOBJ("otro/tumba"));
  AddItem(ALUOBJ("otro/tumba"));
  AddItem(ALUOBJ("otro/tumba"));

  AddExit("oeste",ALUTIIN("cementerio/camino1"));
  AddExit("este",ALUTIIN("cementerio/camino5"));
  SetLocate("cementerio2");
}
