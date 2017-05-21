
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
  ::create();
SetIntShort("un camino en el cementerio");
SetIntLong("  En este punto el camino hace un giro. La niebla empieza a ser algo mas "
"espesa aqui. Aparte de los arbustos vislumbras al oeste la puerta de una "
"pequeña alcoba con la figura de un angel (extrañamente sin cabeza) custodiándola.\n");


AddDetail(({"lapidas","sepulturas","tumbas","lápidas"}),
"  Todas las lapidas tienen una inscripción con el nombre de quien yace en la sepultura.\n");

AddDetail(({"inscripción","inscripcion","nombre","inscripciones"}),
"  Pues consigues leer ... nada, parece elfo pero que muuuy antiguo.\n");

AddDetail (({"niebla"}),
"  Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo el\n"
" cementerio. El resto se trata de una niebla mucho menos densa.\n");

AddDetail (({"matorral","matorrales"}),
" No tienen nada de especial, son solo arbustos secos, tal vez en otra epoca estarian llenos\n"
"de vida para dar algo de color al visitante.\n");

SetIntNoise("  Se puede oir la suave brisa del viento,que mueve la hierba. Se oye algo "
"mas al fondo, cerca del camino,pero desde esta distancia no puedes saber bien"
"de que se trata.\n");
SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddExit("oeste", ALUTIIN("cementerio/cripta/mausoleo1"));
AddExit("sur",ALUTIIN("cementerio/camino1"));
AddExit("norte",ALUTIIN("cementerio/caminox"));
 }

