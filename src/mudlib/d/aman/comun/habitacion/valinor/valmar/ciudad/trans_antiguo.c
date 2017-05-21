/****************************************************************************
fichero: trans_antiguo.c
Autor: Aule

Fecha: 15/10/2012
Descripción: Sala de transporte a los dominios de Simauria
****************************************************************************/

#include "path.h"
inherit ROOM;

create () {
  ::create();
  SetIndoors(1);
  SetIntBright(75);
  SetIntSmell("En el aire percibes el olor salino del océano, la resina de frondosos \n"
  "pinares boreales, la fragancia de los espesos bosques templados, el aroma de las \n"
  "amplias praderas herbosas, el seco viento arenoso del desierto, la tenue brisa \n"
  "proveniente de las nieves perpetuas....");
  SetIntNoise("Escuchas multitud de sonidos procedentes de cada uno de los portales.\n"
  "Se trata de un conjunto sonoro particular, pues el rumor de las olas de los océanos \n"
  "se une  al susurro del viento en las ramas de los árboles, los fríos vientos de alta \n"
  "montaña, el goteo de agua en  umbrías cavernas, el canto de aves marinas, el aullido \n"
  "de lobos, el desprendimiento de aludes, el trajín de grandes ciudades y el triste \n"
  "gemido de vientos fríos sobre páramos olvidados junto con el soplo ardiente \n"
  "procedente de lejanos desiertos.\n");
  SetIntShort("antigua sala de los portales");
  SetIntLong("Esta es la antigua sala de los portales, una cámara alargada y abovedada \n"
    "con las paredes, techo y suelo hechos de mármol negro y pulido.\n"
  "A lo largo de los muros se abren altas arcadas que dan a los distintos lugares de un \n"
    "mundo ya desaparecido, más allá de Arda.\n");
  AddDetail(({"portales","portal"}),
  "Altas arcadas de piedra blanca cerradas por intrincadas verjas de plata.\n"
  "Más allá vislumbras esbozos de un mundo lejano....\n");
  AddExit("endor", "./trans_endor");


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

}