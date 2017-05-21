
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "El sendero sigue hacia el norte y el sur, haciendo que escalofrios recorran tu espalda "
    "por el ambiente que flota en el aire. Las piedrecillas del suelo producen un sonido extraño "
    "cuando caminas, y los trozos en los que aun hay algo de hierba, pero cada vez menos."
    "Los arboles que adornan los laterales del camino producen sombras inquietantes."
    "Todo en este lugar te dice que quizas no deberias estar aqui y que en casita se esta mejor...\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor nauseabundo de la carne putrefacta se extiende por todos lados.\n"
    );
  SetIntNoise(
    "Oyes como se mueven cosas, arañazos y algun tipo de extraño grito.\n"
    );
  AddDetail(({"niebla"}),
    "La niebla en esta zona se hace mas densa, arremolinandose por tus piernas y haciendo\n"
    "que un escalofrio te suba por la espalda.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extraño, como\n"
    "si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que\n"
    "una lapida ha sido arrancada.\n"
    );
  AddDetail(({"arbol","albusto","arboles"}),
    "Parecen muertos por la falta de cuidados, pero una mirada mas exaustiva te dice\n"
    "que aun viven... sera lo unico en este cementerio que aun conserva algo de lo que\n"
    "podamos llamar vida.\n"
    );

  AddExit("norte",ALUTIIN("cementerio/camino3"));
  AddExit("sur",ALUTIIN("cementerio/camino2"));
  AddItem(ALUPNJ("guer_esquel"),REFRESH_DESTRUCT,1);
  SetLocate("cementerio2");
}
