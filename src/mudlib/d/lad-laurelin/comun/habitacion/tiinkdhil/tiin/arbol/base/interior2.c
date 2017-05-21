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
"Estas en un amplio pasillo con las paredes redondeadas y talladas en el arbol.\n"
"El pasillo sigue al este y al oeste, pero al norte y al sur hay dos tuneles,\n"
"que se alejan y se adentran en el interior del mismo al norte ves luz, al sur\n"
"tan solo oscuridad.....\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("norte",TABASE("pasillo1"));
AddExit("sur",TABASE("centro1"));
AddExit("este",TABASE("interior3"));
AddExit("oeste",TABASE("interior1"));

}
