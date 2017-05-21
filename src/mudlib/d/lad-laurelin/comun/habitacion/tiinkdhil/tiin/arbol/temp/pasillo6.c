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
  SetIntShort("");
SetIntLong(
"Estas en el comienzo del pasillo del sotano del Arbol de la Vida.Al oeste ves\n"
"unas escaleras de piedra, la piedra se prolonga hasta aproximadamente la\n"
"mitad del suelo, pero progresivamente va desapareciendo para dar paso a la\n""tierra. De hecho la estancia es un tunel excavado en el suelo Gruesas raices\n"
"revisten las paredes y techo. La luz viene de unas espirales fosforescentes\n"
"colocadas en la pared. Al sur ves una celda. Al este el pasillo continua.\n"
);

AddDetail(({"espirales","luz","fosforescentes","espiral"}),
"Ves la espiral fosforescente:\n"
"                 x\n"
"                 x\n"
"                 x\n"
"                x\n"
"               x\n"
"              x  x\n"
"             x  x x\n"
"           x x   x\n"
"             x  x   x\n"
"              x  x  x\n"
"               x    x\n"
"                xxxx\n"
"A simple vista parece un adorno cualquiera a pesar de su brillante luz, su\n"
"particularidad es que esta hecha de Ilasi, una mezcla entre Fosforo, Renio\n"
"y un 'ingrediente secreto' que solo los elfos conocen. Se emplea para producir\n"
"luz, aunque hay quien asegura que el Ilasi no es mas que magia.\n"
);

SetIntBright(20);
SetIntNoise("El raspar de unas garras diminutas contra la madera se confunden con el eco\n"
	    "de unas botas lejanas.\n");
SetIntSmell("");
SetLocate("");
SetIndoors(1);

AddExit("sur",TASOTANO("celda8"));
AddExit("este",TASOTANO("pasillo7"));
AddExit("oeste",TASOTANO("subida"));

}
