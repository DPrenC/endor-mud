/*
DESCRIPCION  : pasillo interior de la base del arbol
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
"Estas en medio de dos tuneles, ambos perpendiculares, uno en posicion\n"
"horizontal y otro vertical. El que lleva hacia el norte y el sur esta\n"
"muy oscuro, pero el que conduce hacia el oeste es muy luminoso.\n"
"Viniendo del este notas una sensacion extranya.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell(
"Un soplo de aire fresco que viene del oeste, transporta el aroma del bosque.\n"
);
SetLocate("Arbol");
SetIndoors(1);

AddExit("norte",TABASE("interior1"));
AddExit("sur",TABASE("bajada1"));
AddExit("este",TABASE("centro1"));
AddExit("oeste",TABASE("pasillo2"));

}
