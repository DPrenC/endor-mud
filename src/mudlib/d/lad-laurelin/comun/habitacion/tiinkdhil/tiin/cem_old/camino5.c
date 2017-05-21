/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/ camino5.c
NOTAS:
CREACION :  Alura (Julio 2000)
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un camino en el cementerio");
SetIntLong(
"  Ante ti ves que el cementerio consta de varios caminillos entrelazados, entre\n"
"los cuales hay sepulturas y edificios.\n"
" En los lindes del camino se sitúan varios imponentes abetos, que custodian\n"
"algunas tumbas de la vieja gente.\n");

AddDetail(({"lápidas","sepulturas","tumbas"}),
"  Son lápidas sencillas talladas en mármol con motivos arbóreos grabados.\n"
" En ellas descansan los restos de elfos y peregrinos.\n");

AddDetail (({"niebla"}),
"  Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo el cementerio,\n"
"el resto se trata de una niebla algo menos densa pero que aun así te impide ver\n"
"el final del camino.\n");

SetIntNoise("  Se puede oir la suave brisa del viento, que mueve la hierba.\n");
SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(25);

AddExit("oeste","camino4");
AddExit("este","camino9");
AddExit("sur","entradacem");
}