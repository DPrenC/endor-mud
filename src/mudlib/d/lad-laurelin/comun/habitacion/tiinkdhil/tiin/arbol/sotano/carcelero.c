/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.
MODIFICACION : [Ch] 10-11-98 Justificado de caracteres a 80.
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("el puesto del Carcelero");
SetIntLong(
"Estas en una habitacion pequenya, sobria y escueta. La luminosidad es muy\n"
"buena debido a que todo el techo esta lleno de espirales fosforescentes pero\n"
"por las paredes no hay ninguna, ya que estan llenas de alcayatas que sirven\n"
"para sujetar llaves de diversos tamanyos y formas. En el centro hay una mesa\n"
"y una silla al lado de la misma. Hacia el suroeste se encuentra la salida.\n"
);

AddDetail(({"mesa","silla"}),
"Observas una mesa con su silla respectivajusto en el centro de la estancia,\n"
"son de madera, y estan bastante gastadas, pero en concreto la silla es muy\n"
"comoda, como si estuviese preparada para esperar sentado durante mucho tiempo.\n"
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

AddExit("suroeste",TASOTANO("subida"));

}