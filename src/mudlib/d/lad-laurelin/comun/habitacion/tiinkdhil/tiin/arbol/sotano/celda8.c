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
"Estas en una celda muy oscura y polvorienta, parece como si hubieran excavado\n"
"en la tierra para hacerla una cueva, la unica madera que hay son unas vigas\n"
"apuntalando el techo, y el marco de la puerta. El suelo esta recubierto por\n"
"hojas secas y paja. De las paredes salen hilillos y ramitas de la raiz que al\n"
"atravesar las paredes de tierra hacen peligrar la estabilidad de la estancia.\n"
"La unica salida visible es la puerta norte de la celda.\n"
);

AddDetail (({"paja","hojas","hojas secas"}),
"Ante tus pies ves un hatajo de hojarascas y heno seco muy sucio.\n");

AddDetail (({"viga","vigas"}),
"Unas fuertes vigas de madera muy gruesas aguantan el peso de la habitacion. Por\n"
"algunas partes ves como estan roidas y abujereadas.\n");

SetIntBright(10);
SetIntNoise("El sonido de hojas rompiendose llega desde tus pies.\n");
SetIntSmell(
"Milagrosamente esta zona no esta muy humeda, puedes percibir mas bien el olor al\n"
"polvillo de la tierra que se ha desprendido.\n"
);
SetLocate("");
SetIndoors(1);

AddExit("norte",TASOTANO("pasillo6"));

}