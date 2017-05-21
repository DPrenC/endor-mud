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
"El techo esta convado hacia dentro, no tiene ramas, solo tierra y una espiral\n"
"fosforescente justo en el centro a modo de lampara. Al norte ves una gruesa\n"
"raiz dificultando el acceso. Al sur el camino esta despejado y libre. Las\n"
"paredes son de tierra. Al observar con detenimiento la pared ves unas runas\n"
"grabadas en la tierra. Al este hay una celda que parece estar vacia.\n"
);

AddDetail (({"","",""}),"");

AddDetail(({"espirales","luz","fosforescentes","espiral"}),
"Ves la espiral fosforescente:\n"
"                 x\n"
"                 x\n"
"                 x\n"
"                x\n"
"               x\n"
"              x  x\n"
"             x  x x\n"
"             x x   x\n"
"             x  x   x\n"
"              x    x\n"
"               xxxx\n"
"A simple vista parece un adorno cualquiera a pesar de su brillante luz, su\n"
"particularidad es que esta hecha de Ilasi, una mezcla entre Fosforo, Renio y un\n"
"'ingrediente secreto' que solo los elfos conocen. Se emplea para producir luz,\n"
"aunque hay quien asegura que el Ilasi no es mas que magia.\n"
);

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors(1);

AddExit("norte",TASOTANO("pasillo3"));
AddExit("sur",TASOTANO("pasillo7"));
AddExit("este",TASOTANO("celda6"));

}
