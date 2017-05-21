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
SetIntLong("  El camino aqui se estrecha, y una fila de arboles podridos bordean sus lados.\n"
           "Ves que vuelve a girar en este punto, y las lápidas están como si un gran\n"
           "terremoto hubiera sacudido toda la tierra.\n");
AddDetail(({"lapidas","sepulturas","tumbas"}),"  Las lapidas son de construccion simple, pero en estas estan mal\n"
                                              "colocadas da la sensacion de que alguien ha estado cavando, sobre\n"
                                              "cada una de las tumbas.\n");

AddDetail(({"arbol","arboles"}),"  Parecen ser cipreses delgados y altos que apuntan al cielo, forman una\n"
                                "pared tupida junto con las lapidas, a los lados del camino.\n");

AddDetail (({"niebla"}),"  En este punto del camino la niebla ya casi ha desaparecido excepto\n"
                        "cerca del suelo donde aun permanece impidiendo ver con claridad el suelo.n");

SetIntNoise("  El ruido antes inapreciable se empieza a escuchar con fuerza, parece que alguien se\n"
            "este arastrando entre los arboles\n");

SetIntSmell("  Empieza a oler a carne podrida...\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");
AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");

AddExit("norte","camino14");
AddExit("oeste","camino9");
}