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
"Acabas de entrar en el pasillo del Arbol de la Vida. Es un tunel excavado en\n"
"la tierra, pero el techo tiene una forma mas o menos abovedada con gruesas\n"
"raices configurandolo. Seria muy oscuro de no ser por unas extranyas espirales\n"
"fosforescentes que estan colgadas de las paredes. En general todo parece muy\n"
"sucio y descuidado. Al oeste ves una puerta, al norte el pasillo sigue.\n"
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

AddExit("norte",TASOTANO("pasillo1"));
AddExit("sur",TASOTANO("subida"));
AddExit("oeste",TASOTANO("recluta"));

}
