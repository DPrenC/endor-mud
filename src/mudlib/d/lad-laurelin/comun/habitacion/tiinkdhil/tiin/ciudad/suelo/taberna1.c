/*
DESCRIPCION  : Taberna el Vegetariano
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : Creado por chantiel
MODIFICACION : [l] Lonerwolf
               [l] 18/01/03 Joer! el chantiel solo ha hecho el esqueleto de la habitacion
                  Por lo menos le he puesto la salida, mientras me invento la descripcion
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("");
  SetIntLong("");

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("hirak2"));

}
