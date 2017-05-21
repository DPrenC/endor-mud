/*
DESCRIPCION : Celda de gran tamanyo.
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICADO POR : Avengelyne, la mujer fatal.
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un calabozo del Arbol de la Vida");
SetIntLong(
"Estas en una celda ENORME, esta lujosamente amueblada en comparacion con\n"
"otras celdas. Hay un catre junto a la pared y justo delante del mismo, una\n"
"mesa y una silla. Lo extranyo es que los muebles son de dimensiones muy\n"
"grandes, a juego con la estancia, como si estuviera preparada para albergar\n"
"a un gigante. Hacia el este esta la salida de la estancia.\n"
);

AddDetail(({"catre"}),
"Ves un catre que esta en buenas condiciones para ser lo que es, es muy grande\n"
"haciendo juego con la habitacion, tiene una manta y una almohada colocadas de\n"
"cualquier forma encima. Hace falta tener una gran estatura para poder subirse a\n"
"el sin problemas.\n"
);
AddDetail(({"mesa"}),
"Ves una mesa muy grande de disenyo tosco y simple, esta astillada y tiene\n"
"cientos de agujeritos producidos seguramente por la carcoma, sobre todo por la\n"
"zona de las patas. A simple vista observas que su superficie tiene una forma\n"
"rugosa e irregular.\n"
);
AddDetail(({"silla"}),
"Ves una silla de una sola pata muy gruesa colocada en el centro de la\n"
"estancia. Esta carcomida y apolillada, no tiene respaldo y parece mas\n"
"bien un objeto de decoracion que un objeto para usar.\n"
);

SetIntBright(10);
SetIntNoise(
"Hay mucho ruido que proviene de la habitacion contigua.\n"
);
SetIntSmell(
"Parece que hace mucho tiempo que no han utilizado esta celda por el olor mohoso\n"
"y concentrado que percibes.\n"
);
SetLocate("");
SetIndoors(1);

AddExit("este",TASOTANO("pasillo1"));

}