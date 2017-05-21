/****************************************************************************
fichero: transporte.c
Autor: Kastwey
Descripción: Sala de teletransporte
****************************************************************************/

#include "path.h"
inherit ROOM;

create () {
  ::create();
  SetIndoors(1);
  SetIntBright(75);
  SetIntSmell("hueles a humo de cigarrillo... Seguro que halguien ha estado fumando por aquí!");
  SetIntNoise("Escuchas el susurro de los portales de teletransporte");
  SetIntShort("sala de transporte de Kastwey");
  SetIntLong("Te encuentras en la sala de transportes de Kastwey.\n"
"Aquí podrás dirigirte a casi cualquier parte de simauria, gracias a "
"los numerosos portales de teletransportes situados en toda la habitación.\n");
  AddDetail(({"portales","portal"}),"Son puertas magicas que te llevan donde quieres ir.\n");

  AddExit("atbalnin",   "/d/lad-laurelin/comun/habitacion/atbalnin/bosque/bosque17");
  AddExit("zarkam",     "/d/akallab/comun/habitacion/akallab/zarkam/ciudad/plaza_01");
  AddExit("cored",      "/d/simauria/comun/habitacion/marhalt/fortaleza/fortaleza/lord");
  AddExit("khaannu",    "/d/kha-annu/comun/habitacion/kha-annu/ciudad/puertanor/hall2");
  AddExit("glucksfall", "/d/goldhai/comun/habitacion/glucksfall/muelle");
  AddExit("nandor",     "/d/simauria/comun/habitacion/marhalt/nandor/calle0");

  AddExit("azzor",      "/d/akallab/comun/habitacion/akallab/azzor/puerto/muelle00");
  AddExit("berat",      "/d/simauria/comun/habitacion/simauria/berat/muelle01");
  AddExit("crowy",      "/d/goldhai/comun/habitacion/bosque_oscuro/alrededor_crowy1");
  AddExit("flenton",    "/d/kenton/comun/habitacion/flenton/plaza");
  AddExit("gaddaro",    "/d/akallab/comun/habitacion/akallab/azzor/camino/camino11");
  AddExit("goldhai",    "/d/goldhai/comun/habitacion/puerto/muelle2");
  AddExit("gorat",      "/d/simauria/comun/habitacion/caminos/nandor-simauria/puerto");
  AddExit("limbo",      "/d/limbo/comun/habitacion/limbo/limbo/camino03");
  AddExit("narad",      "/d/akallab/comun/habitacion/akallab/azzor/camino/camino01");
  AddExit("shad",       "/d/simauria/comun/habitacion/marhalt/cueva/cueva21");

  AddExit("asesino",    "/guilds/asesinos/gremio");
  AddExit("aventurero", "/guilds/aventurero/aventurero");
  AddExit("conjurador", "/guilds/conjuradores/gremio");
  AddExit("guardabosques","/guilds/guardabosques/gremio");
  AddExit("guerrero",   "/guilds/guerreros/sedes/nandor/sede_nandor");
  AddExit("kisala",     "/guilds/kisalas/gremio");

  AddExit("este", TORRE("rooms/kastwey/workroom"));

}