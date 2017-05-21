/*
DESCRIPCION  : Camino que conduce a Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino01.c
MODIFICACION : 10-01-97 [angor] Creacion.
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia Stohenge.");
  SetIntLong("Una vez dejado atras el bosque, frente a ti se alza imponente el "
"monumento de Stonehenge. Desde el exterior, Stonehenge parece un inmenso "
"circulo formado por arcos de piedra de grandes dimensiones, sobre el que "
"sobresale el monolito situado en su interior. Hacia el oeste de aqui "
"siguiendo el camino, uno de estos arcos permite acceder a su interior.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores del bosque inundan el ambiente de una suave fragancia.\n");
 SetLocate("isla Limbo");

AddExit("oeste",STONE("st_entrada"));
AddExit("este",LIMBO("camino00"));

SetIndoors(0);

}

