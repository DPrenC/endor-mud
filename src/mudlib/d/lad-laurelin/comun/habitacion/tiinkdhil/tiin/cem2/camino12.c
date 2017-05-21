#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Estas delante de un mausoleo, es grande e imponente, pero la falta de cuidados hace que su aspecto no tenga el esplendor de epocas pasadas. La tierra a los lados del camino parece estar removida, como si lo que descansara en ella no quisiera seguir aqui. Son pensamientos y situaciones extrañas para estar donde estas.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor nauseabundo a carne putrefacta se extiende por todos lados.\n"
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
  AddExit("sur","camino14.c");
  AddExit("este","mausoleo7.c");
  AddExit("norte","camino13.c");
  SetLocate("cementerio2");
}
