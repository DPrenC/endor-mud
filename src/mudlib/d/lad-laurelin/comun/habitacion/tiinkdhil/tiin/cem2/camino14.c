#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Estas en el camino derecho del cementerio, en este lado un par de mausoleos de aspecto desali�ado y matratado por el tiempo se alzan haciendo de la vista algo monotono. Unos peque�os arboles adornan los laterales del camino, dandole un toque tetrico a la escena.\n"
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
    "as� te impide ver el final del camino.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extra�o, como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que una lapida ha sido arrancada.\n"
    );
  AddDetail(({"arboles","arbol","arbusto"}),
    "Parece que esten muy descuidados, y que hayan sobrevivido gracias a sus propios medios y a las lluvias que de vez en cuando les proporcionan algo de agua.\n"
    );
  AddExit("sur","camino11.c");
  AddExit("norte","camino12.c");
  SetLocate("cementerio2");
}
