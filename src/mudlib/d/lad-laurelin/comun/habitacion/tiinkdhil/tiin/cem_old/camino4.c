/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un camino en el cementerio");
SetIntLong(" No tienes ni idea de por donde vas. La niebla apenas te impide ver nada,\n"
           "exceptuando algunos matorrales secos junto a las lápidas.\n");

AddDetail(({"lápidas","sepulturas","tumbas"}),
"  Todas las lápidas tienen una inscripción con el nombre de quien yace en la sepultura.\n");

AddDetail (({"niebla"}),
"  Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo el cementerio,\n"
"el resto se trata de una niebla algo menos densa pero que aun así te impide ver\n"
"el final del camino.\n");

AddDetail (({"matorral","matorrales"}),
" No tienen nada de especial, son solo arbustos secos, tal vez en otra epoca estarian llenos\n"
"de vida para dar algo de color al visitante.\n");

SetIntNoise("  Se puede oir la suave brisa del viento,que mueve la hierba.Se oye algo mas\n"
            "al fondo, cerca del camino,pero desde esta distancia no puedes saber bien de\n"+
             	    "que se trata.\n");
SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddExit("oeste","camino1");
AddExit("este","camino5");
}