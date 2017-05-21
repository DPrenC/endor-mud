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
"Estas en una estancia espaciosa y muy regular en comparacion con otras. La\n"
"unica nota discordante la pone una pared lateral rugosa (seguro que es parte\n"
"de la raiz). En el techo ves muchas ramas entrecruzadas, y en la pared del\n"
"fondo (recubierta con tierra) observas unos extranyos signos.\n"
);

AddDetail(({"signos","senyal","extranyos"}),
"Escrito con mano temblorosa lees el siguiente mensaje:\n"
"          Al enrolarme desee\n"
"          ver lugares extranyos y magicos\n"
"          pero jamas imagine\n"
"          verme encerrado bajo un arbol\n"
"          pues de esta mazmorra inexcrutable\n"
"          nadie puede salir\n"
"          asi acabe yo\n"
"          cautivo hasta morir\n"
"          Y con la llegada de la muerte\n"
"          mi espiritu se libero\n"
"          por eso le canto a ella\n"
"          mi Angel Vengador .\n"
);

SetIntBright(10);
SetIntNoise("Desde la lejania se olle una especie de murmullo");
SetIntSmell("El olor a humedad es muy penetrante aqui");
SetLocate("");
SetIndoors(1);

AddExit("oeste",TASOTANO("pasillo5"));

}