/*
DESCRIPCION  : Ciudad de Tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : Creado por Chantiel
MODIFICACION : [l] Lonerwolf
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();

SetIntShort("la calle Hirak");
SetIntLong("Estás en el camino de Hirak de la ciudad de Tiinkdel. Al sur está\n"
	   "una tienda de artículos generales. Al oeste continúa el camino\n"
	   "de hirak y al este está el cruce entre el camino de Hirak y la\n"
	   "calle del Anochecer. Detrás de la Tienda se encruntra el grande\n"
	   "e imponente árbol de la vida.\n"
);

AddDetail (({"arbol","arbol de la vida","árbol","árbol de la vida"}),
	  "Es un árbol Inmensamente grande que no te permite ver que más hay\n"
	  "hacia el sur.\n");

SetIntNoise("Escuchas el cantar de elfos que supones se encuentran en el arbol");
SetIntSmell("Hueles ligeramente el aroma a savia de árbol");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("ti_gene"));
AddExit("este",TCSUELO("cruce3"));
AddExit("oeste",TCSUELO("hirak4"));

}
