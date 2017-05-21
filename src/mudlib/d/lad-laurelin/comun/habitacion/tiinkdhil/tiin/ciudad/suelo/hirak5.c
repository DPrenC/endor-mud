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
SetIntLong("Est�s en el camino de Hirak de la ciudad de Tiinkdel. Al sur est�\n"
	   "una tienda de art�culos generales. Al oeste contin�a el camino\n"
	   "de hirak y al este est� el cruce entre el camino de Hirak y la\n"
	   "calle del Anochecer. Detr�s de la Tienda se encruntra el grande\n"
	   "e imponente �rbol de la vida.\n"
);

AddDetail (({"arbol","arbol de la vida","�rbol","�rbol de la vida"}),
	  "Es un �rbol Inmensamente grande que no te permite ver que m�s hay\n"
	  "hacia el sur.\n");

SetIntNoise("Escuchas el cantar de elfos que supones se encuentran en el arbol");
SetIntSmell("Hueles ligeramente el aroma a savia de �rbol");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("ti_gene"));
AddExit("este",TCSUELO("cruce3"));
AddExit("oeste",TCSUELO("hirak4"));

}
