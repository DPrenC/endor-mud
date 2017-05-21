#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras delante de un pequeño mausoleo.La niebla que hay en esta zona no te permite verlo muy bien, pero hay un pequeño camino, bordeado por unos arbustos secos y descoloridos . Una pequeña fuente con lo que parece la estatua de un niño se alza en un lateral.\n"
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
  AddExit("nordeste","camino5a.c");
  AddExit("oeste","mausoleo2.c");
  AddExit("sur","caminox.c");
  SetLocate("cementerio2");
}
