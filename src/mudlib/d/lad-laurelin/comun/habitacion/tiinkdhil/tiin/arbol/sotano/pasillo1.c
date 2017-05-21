/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/tiin/arbol/sotano/
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
"En el techo solo hay una raiz muy fina que no sirve para sujetar bien la\n"
"tierra, por eso hay vigas de madera en el techo y en las paredes apuntalando\n"
"el pasillo para evitar que se desplome. Ves dos puertas, una al norte y otra\n"
"al oeste, ambas parecen mazmorras, por la puerta de madera y con una ventana\n"
"en el centro con barrotes de hierro, pero la puerta norte no tiene ventana y\n"
"parece cerrada. El pasillo se extiende al sur y al este.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors(1);

AddExit("norte", TASOTANO("celda1"));
AddExit("sur",TASOTANO("pasillo4"));
AddExit("este",TASOTANO("pasillo2"));
AddExit("oeste",TASOTANO("celda4"));
/* AddDoor("p1", "norte", TASOTANO("celda1"),"puerta","La puerta da hacia un calabozo. ",0,1); */
}
