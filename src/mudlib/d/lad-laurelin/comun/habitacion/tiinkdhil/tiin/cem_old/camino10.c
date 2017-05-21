/*
DESCRIPCION  :  Pues un caminillo estrecho por las tumbas
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/ camino10.c
NOTAS:
CREACION :  ALura (Julio del 2000)
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un camino estrecho por las tumbas");
SetIntLong(
"  La mayoria de tumbas que te rodean están levantadas, o no tienen nada dentro.\n"
"Al sur ves las paredes de un gran panteón, del que sale una columna de humo\n"
"tal vez por alguna entrada a este.\n");


AddDetail(({"lapidas","sepulturas","tumbas"}),"  No ves nada más especial en ellas.\n");

AddDetail (({"niebla"}),"  En este punto del camino la niebla ya casi ha desaparecido excepto\n"
                        "cerca del suelo donde aun permanece impidiendo ver con claridad el suelo.n");

AddDetail (({"panteón"}),
"  Es una obra de arte gigantesca que destaca del cementerio porque no tiene la\n"
"misma fina y delicada estructura que el resto de lugares. Figuras como gárgolas\n"
"y otros horrorosos seres pueblan sus paredes.\n");

SetIntNoise("  Se oye un ruido familiar, parece ser el de un fuego encendido.\n");

SetIntSmell("  Definitivamente huele a carne podrida.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");

AddExit("suroeste","camino13");
AddExit("oeste","camino8");
}