/*
DESCRIPCION  : Estatua del elemento de tierra en Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/st_tierra.c
MODIFICACION : 25-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("la estatua del elemento tierra");
  SetIntLong("El corredor interior entre los dos anillos de piedra de Stonehenge continua de "
"oeste a este. Te hallas junto al muro interior de este monumento frente a un "
"arco que permite llegar al centro de Stonehenge. En el medio del corredor hay "
"una estatua que representa al elemento 'Tierra' que caracteriza a todas las "
"razas cuyos portales se encuentran en esta zona de Stonehenge.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

 AddDetail(({"estatua","estatua de tierra","tierra","elemento tierra"}),
  "Las diversas razas de Simauria fueron construidas por los dioses utilizado para "
  "ello como materia prima los cuatro elementos: tierra, agua, fuego y aire. Aqui "
  "en Stonehenge se han agrupado los portales de las razas segun el elemento que "
  "mas haya influido en su creacion. En concreto frente a ti tienes una estatua "
  "que representa al elemento de tierra. La estatua en si es un un cilindro tallado "
  "en el mismo basalto negro que el monolito. Parece como si no hace mucho hubiesen "
  "desenterrado esta estatua, pues esta recubierta de una fina capa de polvo.\n");

SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
SetIntSmell("El tierra es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);

AddExit("este",STONE("portal_6"));
AddExit("sudeste",STONE("portal_kender"));
AddExit("sur",STONE("portal_enano"));
AddExit("suroeste",STONE("portal_duende"));
AddExit("oeste",STONE("portal_gnomo"));
AddExit("norte",STONE("st_mon_s"));
}
