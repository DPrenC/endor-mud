/*
DESCRIPCION  : Ciudad de tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : Creado por Chantiel
MODIFICACION :  [l] lonerwolf
               19/10/00 [l] coloque la descripciones pertinentes

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("la calle Hirak");
SetIntLong("Estás en el camino de Hirak de la ciudad de Tiinkdel. Al sur está\n"
	   "el árbol gigantesco impidiendote el paso. Al oeste continúa el\n"
	   "camino de Hirak, mientras que al este esta un cruce entre los\n"
	   "caminos de Hirak y el Viajero.\n"
);

AddDetail (({"arbol","arbol de la vida","árbol","árbol de la vida"}),
	  "Es un árbol Inmensamente grande que no te permite ver que más hay\n"
	  "hacia el sur.\n");

SetIntNoise("Escuchas el cantar de elfos que supones estan en el arbol gigante");
SetIntSmell("Notas un olor a comida proveniente del oeste");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("este",TCSUELO("cruce2"));
AddExit("oeste",TCSUELO("hirak2"));

}
