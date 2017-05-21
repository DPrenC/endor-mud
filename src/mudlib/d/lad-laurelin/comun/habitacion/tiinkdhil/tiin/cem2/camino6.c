#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "En esta parte del camino te sientes empequeñecido por los mausoleos que ves, dos de tamaño medio y uno grande al fondo.Aqui el aspecto de todo, aunque descuidado, denota que ha sido tratado mejor, y los arboles que franquean la entrada a los mausoleos conservan parte de sus ramas y hojas verdes.\n"
    "Trozos de madera alfombran un lateral en lo que parece la base de una cruz.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor a podrido por aqui es mas suave, y una brisa hace llegar un olor como de rosas.\n"
    );
  SetIntNoise(
    "Una melodia que no identificas llega desde algun lugar cercano.\n"
    );
  AddDetail(({"niebla"}),
    "Aqui, la niebla, aunque presente, no es tan fuerte y permite ver con claridad lo que te rodea\n"
    );
  AddDetail(({"arboles"}),
    "Arboles aun vivos recorren los laterales de este camino, haciendo que parezca estar en mejor estado que el resto del cementerio.\n"
    );
  AddDetail(({"madera","trozos"}),
    "Trozos de madera podrida estan esparcidos por todo el lateral del camino junto a la base de lo que parece haber sido una cruz.\n"
    );
  AddDetail(({"cruz"}),
    "Ahora ya desaparecida, la base de piedra en que se sustentaba permanece firme, rodeada por los restos de este simbolo sagrado.\n"
    );
  AddExit("norte","camino7.c");
  AddExit("sur","Hab_radhul.c");
  AddExit("oeste","mausoleo3.c");
  AddExit("este","mausoleo5.c");
  SetLocate("cementerio2");
}
