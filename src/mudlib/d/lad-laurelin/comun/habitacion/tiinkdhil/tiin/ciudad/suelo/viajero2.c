/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("el camino El Viajero");
SetIntLong(
"A tu alrededor puedes contemplar una gran cantidad de gigantescos arboles. Hay\n"
"un serpenteante camino entre ellos, por el que se puede transitar sin ninguna\n"
"dificultad. A lo lejos el gigantesco arbol parece que se hace aun mayor. Hacia\n"
"el este hay una construccion que desentona con el entorno. Desde aqui se puede\n"
"observar un gran letreto que pende en su entrada 'Posada El Viajero'. En las\n"
"alturas divisas mas lianas y puentes. Hacia el sur el camino se dirige hasta\n"
"las cercanias del gigantesco arbol.\n");

AddDetail (({"construccion","posada","Posada","Posada el Viajero"}),
"Se trata de una edificacion de origen humano, que parece estar encajada entre\n"
"dos arboles. Tiene un par de pisos de altura y el techo es de teja cocida. El\n"
"exterior esta recubierto por una capa de cal. Por algunos sitios se ha caido.\n");

SetIntNoise("");
SetIntSmell("");
SetLocate("Ciudad Tiink");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("salida1"));
AddExit("sur",TCSUELO("acceso1"));
AddExit("este",TCSUELO("posada1"));


}
