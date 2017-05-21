
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
   ::create();
   SetIntShort("la entrada al cementerio");
   SetIntLong( "una niebla densa que se levanta a corta distancia del suelo pero que a lo\n"
             "lejos, te impide ver con claridad. Hay un camino hacia el norte que te conduce\n"
             "por entre las lapidas y tumbas de los que algun dia existieron.\n");

    AddDetail(({"lapidas","sepulturas","tumbas"}),
  "  Todas las lapidas tienen una inscripcion con el nombre de quien yace en la\n"
  "sepultura.\n");

       AddDetail (({"niebla"}),
  "  Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
   "el cementerio, el resto se trata de una niebla mucho menos densa pero que aun\n"
  "así te impide ver el final del camino.\n");

 SetIntNoise(  "  Se puede oir la suave brisa del viento,que mueve la hierba. Se oye algo mas\n"
  "al fondo cerca del camino,pero desde esta distancia no puedes saber bien de que\n"
  "se trata.\n");

 SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");
 SetLocate("Cementerio2");
 SetIndoors (0); /* 0 exterior; 1 interior */
 SetIntBright(20);
 AddExit("norte",ALUTIIN("cementerio/camino5"));
 AddExit("este",ALULAGO("bosque/cam5"));
 }
