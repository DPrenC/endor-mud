
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras en un cruce de caminos. Al sur puedes ver como se alzan impresionantes "
    "mausoleos. Dos estatuas de unos bellos angeles franquean la entrada de este camino, el cual "
    "parece llevarte a una parte mas rica del cementerio.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor nauseabundo de la carne putrefacta se extiende por todos lados.\n"
    );
  SetIntNoise(
    "Oyes como se mueven cosas, arañazos y algun tipo de extraño grito.\n"
    );
  AddDetail(({"niebla"}),
    "La niebla parece formar figuras solidas que tienen aspectos amenazadores, crees distinguir "
    "movimientos por todos lados... sera real o una ilusion de tu miedo?\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño, como si "
    "alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que "
    "una lapida ha sido arrancada.\n"
    );
  AddDetail(({"estatua","estatuas"}),
    "Ambas estatuas representan unos bellos angeles con sus alas desplegadas. Sus caras\n"
    "han sido masacradas con furia por algun tipo de criatura.\n"
    );
  AddExit("este",ALUTIIN("cementerio/camino10"));

  AddExit("oeste",ALUTIIN("cementerio/camino5a"));
  AddExit("sur",ALUTIIN("cementerio/camino7"));
  /*AddExit("norte",ALUTIIN("cementerio/bajada1"));*/
  SetLocate("cementerio2");
}
