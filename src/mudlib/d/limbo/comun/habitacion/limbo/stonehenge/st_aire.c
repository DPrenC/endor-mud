/*
DESCRIPCION  : Estatua del elemento de aire en Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/st_aire.c
MODIFICACION : 25-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("la estatua del elemento aire");
  SetIntLong("El corredor interior entre los dos anillos de piedra de Stonehenge continua de "
"oeste a este. Te hallas junto al muro interior de este monumento frente a un "
"arco que permite llegar al centro de Stonehenge. En el medio del corredor hay "
"una estatua que representa al elemento 'Aire' que caracteriza a todas las razas "
"cuyos portales se encuentran en esta zona de Stonehenge.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

 AddDetail(({"estatua","estatua de aire","aire","elemento aire","remolino","viento"}),
  "Las diversas razas de Simauria fueron construidas por los dioses utilizado para "
  "ello como materia prima los cuatro elementos: tierra, agua, fuego y aire. Aqui "
  "en Stonehenge se han agrupado los portales de las razas segun el elemento que "
  "mas haya influido en su creacion. En concreto frente a ti tienes una estatua "
  "que representa al elemento de aire. La estatua en si es un un cilindro tallado "
  "en el mismo basalto negro que el monolito. Es curioso, en torno a la estatua hay "
  "un pequenyo remolino de aire, pese a no soplar viento en Stonehenge.\n");

SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);

AddExit("este",STONE("portal_1"));
AddExit("nordeste",STONE("portal_humano"));
AddExit("norte",STONE("portal_medio_elfo"));
AddExit("noroeste",STONE("portal_elfo"));
AddExit("oeste",STONE("portal_elfo_oscuro"));
AddExit("sur",STONE("st_mon_n"));
}
