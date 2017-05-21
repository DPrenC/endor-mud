/*
DESCRIPCION  : Estatua del elemento de agua en Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/st_agua.c
MODIFICACION : 23-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("la estatua del elemento agua");
  SetIntLong("El corredor interior entre los dos anillos de piedra de Stonehenge continua de "
"norte a sur. Te hallas junto al muro interior de este monumento frente a un "
"arco que permite llegar al centro de Stonehenge. En el medio del corredor hay "
"una estatua que representa al elemento 'Agua' que caracteriza a todas las razas "
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

 AddDetail(({"estatua","estatua de agua","agua","elemento agua","manantial"}),
  "Las diversas razas de Simauria fueron construidas por los dioses utilizado para "
  "ello como materia prima los cuatro elementos: tierra, fuego, agua y aire. Aqui "
  "en Stonehenge se han agrupado los portales de las razas segun el elemento que "
  "mas haya influido en su creacion. En concreto frente a ti tienes una estatua "
  "que representa al elemento de agua. La estatua en si es un un cilindro tallado "
  "en el mismo basalto negro que el monolito, del que brota, inexplicablemente, "
  "un pequenyo manantial de agua.\n");

SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);

AddExit("sur",STONE("portal_4"));
AddExit("sudeste",STONE("portal_logath"));
AddExit("este",STONE("st_entrada"));
AddExit("nordeste",STONE("portal_draconiano"));
AddExit("norte",STONE("portal_3"));
AddExit("oeste",STONE("st_mon_e"));
}
