/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/tiin/arbol/base
NOTAS        : [Ch]: Chantiel.
MODIFICACION : [Ch] Añadi la salida hacia el este.
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("");
SetIntLong(
"Estas en el pasillo que conduce al centro del justo del Arbol de la Vida\n"
"Las paredes forman parte del mismo. De no ser por varias antorchas que\n"
"iluminan la zona, la oscuridad seria total. Al oeste llegas al centro\n"
"al norte y sur el pasillo sigue.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("norte",TABASE("interior3"));
AddExit("sur",TABASE("interior8"));
AddExit("este",TABASE("pasillo3"));
AddExit("oeste",TABASE("centro1"));

}
