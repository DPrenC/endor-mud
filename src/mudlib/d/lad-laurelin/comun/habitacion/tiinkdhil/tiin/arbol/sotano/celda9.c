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
SetIntShort("un calabozo del Arbol de la Vida");
SetIntLong(
"Esta celda tiene el techo muy bajo, pero se puede caminar bien por ella.\n"
"Hay una manta tirada de cualquier forma en un rincon. Un palo de madera\n"
"esta situado de forma transversal de una pared a otra, parece que era una\n"
"vieja viga que apuntalaba el techo. Las paredes son todas de tierra y tienen\n"
"extranyos dibujos grabados. La unica salida que hay de la estancia es hacia\n"
"el norte, de vuelta al pasillo.\n"
);

AddDetail(({"dibujos","dibujo","signos","signo"}),
"Escrito en runas elficas lees :\n"
"La libertad es el don mas preciado que se puede tener\n"
"todos los presos darian lo que fuera por tenerla.....\n"
);

SetIntBright(10);
SetIntNoise("");
SetIntSmell(
"El olor a humedad es penetrante, pero afortunadamente se puede respirar bien.\n"
);
SetLocate("");
SetIndoors(1);

AddExit("norte",TASOTANO("pasillo7"));

}