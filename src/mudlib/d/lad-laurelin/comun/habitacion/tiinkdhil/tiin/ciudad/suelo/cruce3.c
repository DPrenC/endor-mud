/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("el cruce entre Calle Hirak y Calle El Amanecer");
SetIntLong(
"Est�s en el cruce entre el camino de Hirak y la calle del Anochecer\n"
"de la ciudad de Tiink. Te impresiona lo inmensamente grande del �rbol\n"
"que ves  al suroeste, al oeste  est� el Camino de Hirak, mientras que\n"
"al sur est� la calle del Amanecer.\n"
	   );

AddDetail (({"arbol","arbol de la vida","�rbol","�rbol de la vida"}),
	  "Es un �rbol Inmensamente grande que no te permite ver que m�s hay\n"
	  "hacia el sur.\n");

SetIntNoise("");
SetIntSmell("");
SetLocate("Ciudad Tiink");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("amanec1"));
AddExit("oeste",TCSUELO("hirak5"));

}