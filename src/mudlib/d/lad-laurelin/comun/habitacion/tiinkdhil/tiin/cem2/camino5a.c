#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "En esta parte el camino  atraviesa en diagonal la parte norte del cementerio, a un lado del camino distinges la pared, desconchada y descuidada por la falta de atencion. Al otro lado por encima de una tapia se distinguen los techos de unos mausoleos altos y con aspecto lujoso.\n"
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
  AddDetail(({"pared"}),
    "Desconchada y descuidada por la falta de cuidados se alza al norte de ti. Es alta.\n"
    );
  AddDetail(({"tapia"}),
    "Una tapia que separa esta parte del cementerio de otra que parece mas rica.\n"
    );
  AddDetail(({"mausoleos"}),
    "Desde aqui no se distinguen demasiado bien, tendras que avanzar mas para poder verlos.\n"
    );
  AddExit("este","camino8.c");
  AddExit("suroeste","camino3.c");
  SetLocate("cementerio2");
}
