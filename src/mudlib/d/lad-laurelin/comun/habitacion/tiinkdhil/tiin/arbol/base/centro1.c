/*
DESCRIPCION  : room que conecta la base con el piso1
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
  SetIntShort("");
SetIntLong(
"Estas justo en el centro del Arbol de la Vida, donde la magia es lo que\n"
"mantiene este lugar. Enfrente hay unas escaleras de caracol talladas en la\n"
"columna de madera situada en la zona central de la estancia. Las escaleras\n"
"conducen al piso superior. En el suelo hay grabadas en runas elficas unos\n"
"extranyos signos que bordean la escalera.\n"
);

AddDetail (({"signos","signo","runas","runa"}),
"Al rodear las escaleras lees el siguiente mensaje:\n"
"          No danyes la columna de madera\n"
"          pues al igual que la sangre que corre por tus venas\n"
"          la savia del arbol que alimenta y da vida\n"
"          tiene su cuerpo en el centro de la escalera.\n"
);

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("norte",TABASE("interior2"));
AddExit("sur",TABASE("interior7"));
AddExit("este",TABASE("interior5"));
AddExit("oeste",TABASE("interior4"));
AddExit("noroeste",TABASE("interior1"));
AddExit("nordeste",TABASE("interior3"));
AddExit("suroeste",TABASE("bajada1"));
AddExit("sudeste",TABASE("interior8"));

}
