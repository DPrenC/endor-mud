#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "En esta parte del sendero hay unos arboles que hacen de pasillo hacia una zona\n"
    "callada...un bello mausoleo que se extiende al oeste, parece que este en perfecto estado, a diferencia de las partes del cementerio que has visto hasta ahora. Extraño... nada se acerca a esa zona.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor a carne putrefacta impregna el ambiente.\n"
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
  AddExit("norte","caminox.c");
  AddExit("oeste","mausoleo1.c");
  AddExit("sur","camino1.c");
  SetLocate("cementerio2");
}
