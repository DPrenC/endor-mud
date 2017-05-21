
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "En este lado del cementerio las lapidas se amontonan contra una de las paredes, la "
    "niebla parece viva y te hace pensar cosas extrañas. A lo lejos hacia el este se distinge "
    "una pared, hacia el oeste solo ves un camino con tumbas a los lados que parece perderse "
    "en un mar de niebla.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor es cada vez mas fuerte... huele... a rancio y a muerte...\n"
    );
  SetIntNoise(
    "Tu imaginación te esta gastando una mala pasada... porque dirias que escuchas pasos... "
    "como de algo que se arrastra entre la niebla.\n"
    );
  AddDetail(({"niebla","bruma"}),
    "Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
    "el cementerio, el resto se trata de una niebla mucho menos densa pero que aun\n"
    "así te impide ver el final del camino.\n"
    );
  AddDetail(({"lapidas"}),
    "Lapidas amontonadas y con aspecto de haber sido arrancadas estan amontonadas\n"
    "contra una pared cercana.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño,\n"
    "como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares\n"
    "en los que una lapida ha sido arrancada.\n"
    );

  AddItem(ALUOBJ("otro/tumba"));

  AddExit("oeste",ALUTIIN("cementerio/camino5"));
  AddExit("este",ALUTIIN("cementerio/camino11"));
  SetLocate("cementerio2");
}

