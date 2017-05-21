/*
DESCRIPCION  : celda de un guardia de la entrada del arbol de la vida

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

MODIFICADO POR AVENGELYNE, LA MUJER FATAL

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la celda de un guardia");
  SetIntLong(
"Te encuentras en una pequeña habitación que parece haber sido la celda de\n"
"algún guardia, pero ahora parece deshabitada, el suelo es de tierra, y las\n"
"paredes están formadas con la corteza del árbol. El techo es muy alto, y\n"
"tiene una espiral en el centro del mismo que está iluminada e inunda la\n"
"estancia con una extraña luz.\n"
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
"Parece que oyes unos pasos recorriendo la estancia contigo\n"
);

SetIntSmell(
"El olor a humedad es muy fuerte, y ademas se mezcla con\n"
"el aroma inconfundible de la madera y de la savia.\n"
);

SetLocate("Arbol");

SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("oeste",TABASE("pasillo4"));

}