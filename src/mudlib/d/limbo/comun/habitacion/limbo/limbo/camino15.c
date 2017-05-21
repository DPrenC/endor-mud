/*
DESCRIPCION  : Cruce en el camino del norte.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino15.c
MODIFICACION : 23-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("un cruce en el camino del Norte");
  SetIntLong(
"Has llegado a un cruce en el camino del Norte. En este punto un camino se separa "
"de la via principal. Este camino desciende hacia la costa nordeste de la isla "
"donde se encuentra una larga y tranquila playa. Junto al camino hay un poste con "
"un mapa con más información. El camino principal sigue ascendiendo suavemente "
"hacia el noroeste donde se halla la zona de entrenamiento para novatos.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"camino del norte","camino","camino del Norte"}),
"El camino del Norte conduce desde el claro del bosque, que se encuentra en el "
"centro de la isla, hacia la zona norte de la misma en la que existe una zona de "
"entrenamiento para los jugadores recien llegados a este mundo.\n");

AddDetail(({"poste","poste con mapa","mapa","informacion"}),
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Mapa de la Isla Limbo\n"   //
  "~~~~~~~~~  ~~~~~~~~~  ~~~~~~~\n"                          //
  "~~~~~~~~ ^^ _       ^^ ~~~~~~  T torre de wizards\n"      //
  "~~~~~~~~ ^^  \\     ^^^^ ~~~~~  A Templo de Asthar\n"     //
  "~~~~~~~~~~    |N    __  ~~~~~  S Stonehenge\n"            //
  "~~~~~~~~~~p_,---._X'  '-p~~~~  M monolito\n"              //
  "~~~~~~~~~ ^ __    \\  ^ ~~~~~~  N parque para novatos\n"  //
  "~~~~~~~~ ^ / M\\__,-f---mmT~~~  P Pueblo\n"               //
  "~~~~~~~~ ^ \\__/S   | ^ ~~~~~~\n"                         //
  "~~~~~~~~~ ^       /\\_^ ~~~~~~ (f) fuente   (m) puente\n" //
  "~~~~~~~~~p---P---'   A ~~~~~~ (^) montanya (~) mar\n"     //
  "~~~.~~~~ ^   |    ^^  ~~~~~~~ (u) puerto   (p) playa\n"   //
  "~~/|\\~~ ^^ ~~u~~ ^^^^ ~~~~~~~\n"                         //
  "~~~|N~~ ^^ ~~~~~~ ^^ ~~~~~~~~  X estás aquí\n"            //
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

SetIntNoise("Solo el dulce trinar de los pájaros altera el silencio.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("noroeste",LIMBO("camino17"));
AddExit("sur",LIMBO("camino09"));
AddExit("nordeste",LIMBO("camino16"));
}
