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
  SetIntShort("la calle del Amanecer");
  SetIntLong("Sigues en la Calle del Amanecer. Al suroeste se ve el gran\n"
	     "�rbol de la vida, al este se encuentra el Gremio de Gerreros\n"
	     "de Tiink, mientras que al sur contin�a la calle del Amanecer.\n"
	     );


AddDetail (({"arbol","arbol de la vida","�rbol","�rbol de la vida"}),
	  "Es un �rbol Inmensamente grande que no te permite ver que m�s hay\n"
	  "hacia el sur.\n");
SetIntNoise("");
SetIntSmell("");
SetLocate("Ciudad Tiink");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("amanec2"));
AddExit("este",TCSUELO("gremio_guerreros"));
AddExit("norte",TCSUELO("cruce3"));
}
