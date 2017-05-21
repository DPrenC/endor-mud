#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Esta parte del camino, que atraviesa en diagonal el cementerio es mas estrecha que los caminos por los que has pasado. La pared del cementerio, desconchada por el tiempo, se extiende por toda esta zona.Hay un gran numero de lapidas apiladas contra ella.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor nauseabundo de la carne putrefacta se extiende por todos lados.\n"
    );
  SetIntNoise(
    "Oyes como se mueven cosas, arañazos y algun tipo de extraño grito.\n"
    );
  AddDetail(({"niebla"}),
    "La niebla parece formar figuras solidas que tienen aspectos amenazadores, crees distinguir movimientos por todos lados... sera real o una ilusion de tu miedo?\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño, como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que una lapida ha sido arrancada.\n"
    );
  AddDetail(({"lapidas"}),
    "Lapidas arrancadas de su lugar se apilan contra la pared.\n"
    );
  AddExit("sudeste","camino13.c");
  AddExit("oeste","camino8.c");
  SetLocate("cementerio2");
}
