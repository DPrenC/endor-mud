#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "El sendero sigue hacia el norte y el sur, haciendo que escalofrios recorran tu espalda\n"
    "por el ambiente que flota en el aire. Las piedrecillas del suelo producen un sonido extra�o\n"
    "cuando caminas, y los trozos en los que aun hay algo de hierba, pero cada vez menos.\n"
    "Los arboles que adornan los laterales del camino producen sombras inquietantes.\n"
    "Todo en este lugar te dice que quizas no deberias estar aqui y que en casita se esta mejor...\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor nauseabundo de la carne putrefacta se extiende por todos lados.\n"
    );
  SetIntNoise(
    "Oyes como se mueven cosas, ara�azos y algun tipo de extra�o grito.\n"
    );
  AddDetail(({"niebla"}),
    "La niebla en esta zona se hace mas densa, arremolinandose por tus piernas y haciendo que un escalofrio te suba por la espalda.\n"
    );
  AddDetail(({"tumbas"}),
    "Hay tumbas en el suelo a los lados del camino, algunas tienen aspecto extra�o, como si alguien hubiera removido la tierra. En otros sitios se adivinan lugares en los que una lapida ha sido arrancada.\n"
    );
  AddDetail(({"arbol","albusto","arboles"}),
    "Parecen muertos por la falta de cuidados, pero una mirada mas exaustiva te dice que aun viven... sera lo unico en este cementerio que aun conserva algo de lo que podamos llamar vida.\n"
    );
  AddExit("norte","camino3.c");
  AddExit("sur","camino2.c");
  SetLocate("cementerio2");
}
