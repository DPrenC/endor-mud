/*
DESCRIPCION  : Cruce en el camino del Sur
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino12.c
MODIFICACION : 30-01-98 [Angor@Simauria] Creacion.
               14-09-98 [Angor@Simauria] Redescripccion y retoques varios.
	       29-06-99 [Angor@Simauria] wrapeado
	       11-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <colours.h>
inherit ROOM;


create() {
  ::create();
  SetIntShort("un cruce en el camino del Sur.");
  SetIntLong("Has llegado a un cruce en el camino del Sur. El Paseo de la "
    "Alameda es un amplio camino que parte de aquí y avanza hacia el este "
    "de la isla Limbo donde se halla el templo de Asthar, el lugar al que "
    "llegan los nuevos seres a este mundo. Junto al camino hay un poste con "
    "un mapa con más información. El camino del Sur sigue descendiendo "
    "suavemente hacia el oeste entre el bosque.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"camino del sur","camino","camino del Sur"}),
  "El camino del Sur conduce desde el claro del bosque, que se encuentra "
  "en en el centro de la isla, hacia la zona sur de la misma en la que "
  "existe un pequeño pueblo de pescadores.\n");

   AddDetail(({"poste","poste con mapa","mapa","informacion","información"}),
 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Mapa de la Isla Limbo\n" //
 "~~~~~~~~~  ~~~~~~~~~  ~~~~~~~\n" //
 "~~~~~~~~ ^^ _       ^^ ~~~~~~  T torre de wizards\n" //
 "~~~~~~~~ ^^  \\     ^^^^ ~~~~~  A Templo de Asthar\n" //
 "~~~~~~~~~~    |N    __  ~~~~~  S Stonehenge\n" //
 "~~~~~~~~~~p_,---._/'  '-p~~~~  M monolito\n" //
 "~~~~~~~~~ ^ __    \\  ^ ~~~~~~  N parque para novatos\n" //
 "~~~~~~~~ ^ / M\\__,-f---mmT~~~  P Pueblo\n" //
 "~~~~~~~~ ^ \\__/S   | ^ ~~~~~~\n" //
"~~~~~~~~~ ^       _X_^ ~~~~~~ (f) fuente   (m) puente\n" //
 "~~~~~~~~~p---P---'   A ~~~~~~ (^) montanya (~) mar\n" //
 "~~~.~~~~ ^   |    ^^  ~~~~~~~ (u) puerto   (p) playa\n" //
 "~~/|\\~~ ^^ ~~u~~ ^^^^ ~~~~~~~\n" //
 "~~~|N~~ ^^ ~~~~~~ ^^ ~~~~~~~~  X estas aquí\n" //
 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("norte",LIMBO("camino10"));
 AddExit("oeste",LIMBO("camino13"));
 AddExit("este",LIMBO("alameda00"));
}

