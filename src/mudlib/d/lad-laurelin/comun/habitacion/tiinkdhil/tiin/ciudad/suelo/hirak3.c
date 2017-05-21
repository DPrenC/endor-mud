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
SetIntLong("Est�s en el camino de Hirak de la ciudad de Tiinkdel. Al sur est�\n"
	   "el �rbol gigantesco impidiendote el paso. Al oeste contin�a el\n"
	   "camino de Hirak, mientras que al este esta un cruce entre los\n"
	   "caminos de Hirak y el Viajero.\n"
);

AddDetail (({"arbol","arbol de la vida","�rbol","�rbol de la vida"}),
	  "Es un �rbol Inmensamente grande que no te permite ver que m�s hay\n"
	  "hacia el sur.\n");

SetIntNoise("Escuchas el cantar de elfos que supones estan en el arbol gigante");
SetIntSmell("Notas un olor a comida proveniente del oeste");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("este",TCSUELO("cruce2"));
AddExit("oeste",TCSUELO("hirak2"));

}
