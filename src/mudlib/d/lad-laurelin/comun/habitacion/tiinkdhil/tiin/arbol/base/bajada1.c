/*
DESCRIPCION  :bajada al sotano del 'árbol de la vida'

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

SUGERENCIAS: hacer que cuando el jugador baje por las escaleras se caiga ,
y baje al sotano directamente.

MODIFICADO POR AVENGELYNE, LA MUJER FATAL

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("las escaleras que bajan al sótano");
  SetIntLong(
"Estás ante unas escaleras de piedra que bajan al sotano del árbol. Son\n"
"escaleras de caracol muy empinadas. Están iluminadas a cada poco gracias\n"
"a varias espirales fosforescentes. Las paredes y el techo siguen formados\n"
"con la corteza del árbol, pero aquí, el suelo no es de tierra , como en\n"
"el resto del árbol, sino de piedra. Al norte y al este el pasillo sigue\n"
"sientes una extraña sensación mágica que proviene del nordeste.\n"
);



AddDetail (({"espirales","luz","fosforescentes"}),
"Ves las espirales fosforescentes:\n"
"             _____________       _____\n"
"	     / ________    \     / ___ \\n"
"           / /	 _____ \    \   / /___\ \\n"
"          | /  /  \  \ |    | | |    || |\n"
"          | |  \__/  | |    | |  \__/ | |\n"
"           \ \______/ /      \ \_____/ /\n"
"            \________/        \_______/\n"
"\n"
"\n"
"Las espirales son uno de los sistemas mas antiguos\n"
"empleados por los elfos para iluminar las habitaciones\n"
"del 'arbol de la vida'. Estan hechas con algun derivado\n"
"del fosforo, aunque hay quien asegura que lo que en\n"
"verdad las ilumina es la presencia de algun tipo de\n"
"magia.\n"
);


SetIntBright(20);
SetIntNoise(
"Escuchas el sonido de unos lamentos y quejidos que\n"
"provienen del sotano del arbol.\n"
);


SetIntSmell(
"Aqui el olor a savia no es tan pronunciado, pero si puedes\n"
"percibir una fuerte humedad.\n"
);

SetLocate("Arbol");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("norte",TABASE("interior4"));
AddExit("este",TABASE("interior7"));
AddExit("abajo",TASOTANO("subida"));
AddExit("nordeste",TABASE("centro1"));
}