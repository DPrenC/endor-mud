/*
DESCRIPCION  : playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/playa00.c
MODIFICACION : 24-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit LIMBO("playa");

create() {
  ::create();
  SetIntShort("la playa de Levante");
  SetIntLong(
"La playa de Levante se extiende ante tí, tanto hacia el sur como hacia el norte "
"de aquí. Las olas, coronadas por estrias de espuma blanca, llegan una y otra vez "
"a la orilla de la playa. Sopla una suave y agradable brisa desde el océano. "
"Un sendero parte hacia el oeste atravesando las dunas del límite de la playa y "
"adentrándose en el bosque. Junto al inicio del sendero hay un poste con un mapa.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"sendero","camino"}),
"El sendero conduce al bosque que se halla al oeste de aquí.\n");

 AddDetail(({"playa","playa de Levante"}), QueryIntLong());

 AddDetail(({"duna","dunas"}),
"Son grandes montones de arena arrastrados por el viento desde la playa hasta el "
"límite del bosque, donde la vegetación contiene su avance.\n");

AddDetail(({"poste","poste con mapa","mapa","informacion","información"}),
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Mapa de la Isla Limbo\n"   //
  "~~~~~~~~~  ~~~~~~~~~  ~~~~~~~\n"                          //
  "~~~~~~~~ ^^ _       ^^ ~~~~~~  T torre de wizards\n"      //
  "~~~~~~~~ ^^  \\     ^^^^ ~~~~~  A Templo de Asthar\n"     //
  "~~~~~~~~~~    |N    __  ~~~~~  S Stonehenge\n"            //
  "~~~~~~~~~~p_,---._/'  '-X~~~~  M monolito\n"              //
  "~~~~~~~~~ ^ __    \\  ^ ~~~~~~  N parque para novatos\n"  //
  "~~~~~~~~ ^ / M\\__,-f---mmT~~~  P Pueblo\n"               //
  "~~~~~~~~ ^ \\__/S   | ^ ~~~~~~\n"                         //
  "~~~~~~~~~ ^       /\\_^ ~~~~~~ (f) fuente   (m) puente\n" //
  "~~~~~~~~~p---P---'   A ~~~~~~ (^) montanya (~) mar\n"     //
  "~~~.~~~~ ^   |    ^^  ~~~~~~~ (u) puerto   (p) playa\n"   //
  "~~/|\\~~ ^^ ~~u~~ ^^^^ ~~~~~~~\n"                         //
  "~~~|N~~ ^^ ~~~~~~ ^^ ~~~~~~~~  X estás aquí\n"            //
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

SetIntNoise("Oyes las olas al llegar a la orilla.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);


AddExit("oeste",LIMBO("camino19"));
AddExit("sur",LIMBO("playa01"));
AddExit("nordeste",LIMBO("playa02"));
}
