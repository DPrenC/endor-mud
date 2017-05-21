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
"Te encuentras en un trozo dela pasillo. Las paredes estan esculpidas en el\n"
"arbol. No ves nada de particular en el ambiente salvo unas antorchas que\n"
"estan encendidas y colgadas en la pared. El pasillo continua al sur y hacia\n"
"el oeste, al suroeste hay una sala.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("sur",TABASE("interior5"));
AddExit("oeste",TABASE("interior2"));
AddExit("suroeste",TABASE("centro1"));

}
