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
"Al igual que pasa con la celda contigua, el techo se va curvando poco a poco,\n"
"sin embargo esta habitacion es mucho mas espaciosa. En esta celda no hay lecho,\n"
"sino un monton de paja. Una jarra de agua y un trozo de pan mohoso estan tirados\n"
"en un extremo de la misma. La salida unica salida esta al oeste.\n"
);

AddDetail(({"paja","heno","monton"}),
"Ves un monton de paja normal y corriente, pero muy sucia situada en un extremo\n"
"de la celda y puesta de cualquier forma.\n"
);
AddDetail(({"pan","agua"}),
"Ves un poco de comida que debe haber sido puesta hace ya bastante tiempo por las\n"
"condiciones tan deterioradas en las que esta.\n"
);

SetIntBright(10);
SetIntNoise("");
SetIntSmell(
"Hueles a heno ,un olor delicioso de no ser porque la humedad ha empezado a\n"
"pudrirlo por completo.\n"
);
SetLocate("");
SetIndoors(1);

AddExit("oeste",TASOTANO("pasillo3"));

}