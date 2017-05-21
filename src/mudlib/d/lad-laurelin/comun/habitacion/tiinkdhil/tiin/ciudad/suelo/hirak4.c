/*
DESCRIPCION  : Ciudad de Tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : Creado por Chantiel
MODIFICACION : [l] Lonerwolf
               [l] 18/01/03 he arreglao la descripcion ya q estaba hecha un lio

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();

SetIntShort("la calle Hirak");
SetIntLong("Estás en el camino de Hirak de la ciudad de Tiinkdel. Al sur está\n"
	   "la oficina de correos de la ciudad. Al oeste se encuentra el cruce\n"
	   "con el camino del Viajero y al este continúa el camino de Hirak.\n"
           "Detrás de la oficina de correos y se haya el imponente gran árbol\n"
           "de la vida.\n"
);

AddDetail (({"arbol","arbol de la vida","árbol","árbol de la vida"}),
	  "Es un árbol Inmensamente grande que no te permite ver que más hay\n"
	  "hacia el sur.\n");

SetIntNoise("Escuchas el cantar de elfos que supones se encuentran en el gran arbol");
SetIntSmell("Hueles ligeramente el aroma de savia de arbol.\n"
            "¿Sera que te estas acostumbrando?");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("correo"));
AddExit("este",TCSUELO("hirak5"));
AddExit("oeste",TCSUELO("cruce2"));

}
