/*
DESCRIPCION  : cruce de caminos en el claro del bosque.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino03.c
MODIFICACION : 12-01-97 [Amgor@Simauria] Creacion.
               30-08-98 [Amgor@Simauria] Anayadido el mapa
10/05/2007, [Y] (Yalin): suprimo función cmd_beber y añado fuente standard.
    Cambio el IntShort a cruce de caminos.
    --------------------------------------------------------------------------------
*/

#include "./path.h"
#include <sounds.h>
inherit ROOM;

public int leer_cmd(string str)
{
 if (!str) return notify_fail("¿Qué es lo que quieres leer?\n",NOTIFY_NOT_VALID)&&0;
 if ((str=="texto")||(str=="letreros")||("poste")||("letrero"))
 {
write("En el letrero se indican las direcciones a los siguientes lugares: "
      "-Parque de entrenamiento, hacia el noroeste.\n" //
      "-Playa de Levante, hacia el nordeste.\n" //
      "-Pueblo de pescadores, hacia el suroeste\n" //
      "-Stonehenge, hacia el oeste.\n" //
      "-Templo de Asthar, hacia el sudeste.\n" //
      "-Torre de Wizards, hacia el este.\n");
return 1;
 }
}

create() {
  ::create();
  SetIntShort("el cruce de caminos en el claro del bosque.");
  SetIntLong(
"Te encuentras en un claro en medio del bosque. En este lugar se cruzan dos "
"caminos: el primero está adoquinado con piedras blancas y va de este a oeste. "
"El segundo, de tierra, cruza el claro desde el sur hacia el norte. Junto al "
"cruce de estos dos caminos hay un poste con varios letreros y un mapa que te "
"indican donde estás y hacia donde ir para llegar a diversos lugares de esta "
"isla. En medio del claro hay una fuente de agua cristalina y refrescante.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

  AddDetail(({"poste","letrero","letreros","textos"}),
  "Clavados en el poste que hay junto al cruce, hay varios letreros que indican "
  "la zona de la isla en la que se encuentran diversos lugares. Seria una buena "
  "idea leerlos para así conocer como llegar a esos lugares.\n");

 AddDetail(({"mapa"}),
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Mapa de la Isla Limbo\n" //
   "~~~~~~~~~  ~~~~~~~~~  ~~~~~~~\n" //
   "~~~~~~~~ ^^ _       ^^ ~~~~~~  T torre de wizards\n" //
   "~~~~~~~~ ^^  \\     ^^^^ ~~~~~  A Templo de Asthar\n" //
   "~~~~~~~~~~    |N    __  ~~~~~  S Stonehenge\n" //
   "~~~~~~~~~~p_,---._/'  '-p~~~~  M monolito\n" //
   "~~~~~~~~~ ^ __    \\  ^ ~~~~~~  N parque para novatos\n" //
   "~~~~~~~~ ^ / M\\__,-fX--mmT~~~  P Pueblo\n" //
   "~~~~~~~~ ^ \\__/S   | ^ ~~~~~~\n" //
   "~~~~~~~~~ ^       /\\_^ ~~~~~~ (f) fuente   (m) puente\n" //
   "~~~~~~~~~p---P---'   A ~~~~~~ (^) montanya (~) mar\n" //
   "~~~.~~~~ ^   |    ^^  ~~~~~~~ (u) puerto   (p) playa\n" //
   "~~/|\\~~ ^^ ~~u~~ ^^^^ ~~~~~~~\n" //
   "~~~|N~~ ^^ ~~~~~~ ^^ ~~~~~~~~  X estas aquí\n" //
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    AddDetail(({"pila"}),"Nada más que un cuadrado de piedra.\n");
    AddDetail(({"caño","caños","canyo","canyos"}),"Simples tubos de metal, "
        "surgiendo del borde de la pila.\n");
    SetIntNoise("Se oye el trinar de los pájaros y el murmullo del agua de "
        "la fuente.\n");
    SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
    SetLocate("isla Limbo");
    SetIndoors(0);

    AddItem(OTRO("fuente"));
    AddExit("oeste",LIMBO("camino02"));
    AddExit("este",LIMBO("camino04"));
    AddExit("norte",LIMBO("camino07"));
    AddExit("sur",LIMBO("camino08"));

    AddRoomCmd("leer","leer_cmd");
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
