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
SetIntShort("el camino del cementerio");
SetIntLong("  El pasillo de lápidas se hace tan intransitable que te hace cambiar de rumbo.\n"
"Al oeste ves un gran panteón, y de él hacia el norte sale una columna de humo.\n"
"Alguien debe haber hecho una fogata a juzgar por la columna de humo.\n"
" Al este ves un viejo y grande mausoleo.\n");


AddDetail(({"lapidas","sepulturas","tumbas"}),"  Las lápidas son de construccion simple, pero en estas estan mal\n"
                                              "colocadas da la sensación de que alguien ha estado cavando, sobre\n"
                                              "cada una de las tumbas.\n");

AddDetail (({"niebla"}),"  En este punto del camino la niebla ya casi ha desaparecido excepto\n"
                        "cerca del suelo donde aun permanece impidiendo ver con claridad el suelo.n");

AddDetail (({"panteon"}),
"  Es una obra de arte gigantesca que destaca del cementerio porque no tiene la\n"
"misma fina y delicada estructura que el resto de lugares. Figuras como gárgolas\n"
"y otros horrorosos seres pueblan sus paredes.\n");

SetIntNoise("  Se oye un ruido familiar, parece ser el de un fuego encendido.\n");

SetIntSmell("  Definitivamente huele a carne podrida.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");
AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");

AddExit("sur","camino12");
AddExit("este","mausoleo8");
AddExit("nordeste","camino10");
}