/*
DESCRIPCION  : Ciudad de Tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/tiin/ciudad/suelo/cruce2.c
NOTAS        : Creado Por chantiel
MODIFICACION :  [l] lonerwolf
               19/10/00 [l] coloque la descripciones pertinentes

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("el cruce entre el Camino El Viajero y el Camino Hirak");
SetIntLong("Has llegado a un cruce entre el camino del Viajero al norte y\n"
	   "el camino de Hirak al este y oeste. Al sur está hay una entrada\n"
	   "al árbol gigantesco que se encuentra en el centro de la ciudad.\n"
	   "\n"
);

AddDetail (({"arbol","arbol de la vida","árbol","árbol de la vida"}),
	  "Es un árbol Inmensamente grande que no te permite ver que más hay\n"
	  "hacia el sur.\n");

SetIntNoise("Escuchas el Canto de algunos elfos que supones se encuentran en el arbol gigante");
SetIntSmell("El olor a savia innunda en ambiente");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("acceso1"));
AddExit("sur",TABASE("pasillo1"));
AddExit("este",TCSUELO("hirak4"));
AddExit("oeste",TCSUELO("hirak3"));

}