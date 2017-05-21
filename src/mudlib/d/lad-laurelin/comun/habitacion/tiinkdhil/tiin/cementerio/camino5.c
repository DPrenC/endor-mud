
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Estas en la entrada del cementerio. Esta descuidada, como si no hubiera "
  "nadie que atendiera el lugar, quizas sea un cementerio abandonado. Un amplio camino se "
  "extiende a izquierda y derecha. Las lapidas de los que descansan aqui se ven sobresalir "
  "entre la niebla de manera tenebrosa.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "Un olor a podrido se extiende por el ambiente poco a poco.\n"
    );
  SetIntNoise(
    "Ruidos como de arañazos se escuchan a lo lejos.\n"
    );
  AddDetail(({"niebla","bruma"}),
    "Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
    "el cementerio, el resto se trata de una niebla mucho menos densa pero que aun\n"
    "así te impide ver el final del camino.\n"
    );



  AddExit("este",ALUTIIN("cementerio/camino9"));
  AddExit("oeste",ALUTIIN("cementerio/camino4"));
  AddExit("sur",ALUTIIN("cementerio/entradacem"));

    AddItem(ALUOBJ("otro/tumba"));
  AddItem(ALUPNJ("espectro"),REFRESH_DESTRUCT,1);
  SetLocate("cementerio2");
}
