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
  SetIntShort("");
SetIntLong(
"Sigues en el pasillo interior del Arbol de la Vida. Estas en una estancia\n"
"muy oscura puesto que ni tan siquiera una antorcha la ilumina. Cuando tus\n"
"ojos se acostumbras a ella observas que las paredes y el techo tienen forma\n"
"semiesferica . Sientes una extranya fuerza magica que viene del sureste. El\n"
"pasillo sigue al sur y al este.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(10);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("este",TABASE("interior2"));
AddExit("sur",TABASE("interior4"));
AddExit("sudeste",TABASE("centro1"));

}
