#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("una cueva");
  SetIntLong(
    "Has entrado en una cueva que no es del tipo de las de la mina.\n"
    "Hay agujeros en las paredes, y una sustancia babosa se escurre\n"
    "por el suelo y paredes formando un pequeño manto.\n"
    "Ahora que te fijas esto parece la madriguera de algo muy desagradable...\n"
    "Algo con pinta de hueso sobresale de la sustancia.\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
    "Huele a muerte.\n"
    );
  SetIntNoise(
    "Ligeros ticks, clicks y glops surgen de vez sitios indeterminados.\n"
    );
  AddDetail(({"hueso","huesos"}),
    "Unos huesos sobresalen de la sustancia, parece haber de algunos animales\n"
     "y quizas los mas grandes sean humanos... aunque algunos humanos muy pequeños...\n"
    );
  AddDetail(({"sustancia","baba"}),
    "Es una sustancia babosa que sale como de todos lados y que forma un manto por el suelo...\n"
    "trozos de huesos y mas porqueria estan sujetos a ella...\n"
    );
  AddExit("oeste",MPISO4+"nivel4-9");
  SetLocate("");
}
