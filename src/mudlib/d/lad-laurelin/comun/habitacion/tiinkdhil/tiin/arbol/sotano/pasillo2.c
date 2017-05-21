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
"La luz aqui es muy intensa, el motivo son las espirales fosforescentes que aqui\n"
"forman un extranyo dibujo, parece un mapa. El techo es muy elevado y esta\n"
"abovedado. Al norte ves una puerta, otra mazmorra, sin duda. Hacia el este y el\n"
"oeste sigue el pasillo.\n"
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

AddExit("norte",TASOTANO("celda2"));
AddExit("este",TASOTANO("pasillo3"));
AddExit("oeste",TASOTANO("pasillo1"));

}
