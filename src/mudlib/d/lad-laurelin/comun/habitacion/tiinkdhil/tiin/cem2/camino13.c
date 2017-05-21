#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras delante de un mausoleo de pequeño tamaño. Un camino de setos muy descuidados\n"
    "te conduce hasta el. La niebla no te permite verlo con demasiada claridad, pero parece estar bien conservado. El camino que te ha traido aqui aparece entre la niebla como una ciudad fantasmal.\n"
    "Con gusto saldrias de aqui rapidamente.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor nauseabundo de la carne putrefacta se extiende por todos lados.\n"
    );
  SetIntNoise(
    "Oyes como se mueven cosas, arañazos y algun tipo de extraño grito.\n"
    );
  AddDetail(({"niebla"}),
    "La niebla en esta zona se hace mas densa, arremolinandose por tus piernas y haciendo que un escalofrio te suba por la espalda.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño, como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que una lapida ha sido arrancada.\n"
    );
  AddDetail(({"setos","seto","arbusto","arbustos"}),
    "Unos arbustos muy descuidados crecen a lo largo del camino que lleva al mausoleo.\n"
    );
  AddExit("sur","camino12.c");
  AddExit("este","mausoleo8.c");
  AddExit("noroeste","camino10.c");
  SetLocate("cementerio2");
}
