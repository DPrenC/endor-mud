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
"Sigues en el pasillo. En esta zona las paredes se estrechan peligrosamente\n"
"dejando tan solo un hueco muy pequenyo para poder pasar. El pasillo sigue\n"
"al norte y al oeste, al noroeste llegas a una gran sala.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("norte",TABASE("interior5"));
AddExit("oeste",TABASE("interior7"));
AddExit("noroeste",TABASE("centro1"));

}
