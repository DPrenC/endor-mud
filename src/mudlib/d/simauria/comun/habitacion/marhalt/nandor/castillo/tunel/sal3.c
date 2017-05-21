/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*                                                                        */
/**************************************************************************/

#include "./path.h"
#include <moving.h>


#define LOCATE "Algun lugar del norte de Marhalt"
inherit SIM_ROOM;

haz_arriba()
{
  tell_room(CASTILLO("camino/camino30"),
    "Unos matorrales se mueven y de ellos sale "+
    TP->QueryName()+".\n");
  write("Subes hacia el hueco...\n.... Y apareces en medio de un camino.\n");
  TP->move(CASTILLO("camino/camino30"),M_GO,"arriba");
  tell_room(MARH("nandor/castillo/tunel/sal3"),
    TP->QueryName()+" sube por el hueco y sale al exterior.\n");
  return 1;
}

create()
{
  ::create();
  SetLocate(LOCATE);
  SetIntShort("la salida de un túnel");
  SetIntLong(
    "Estás en un oscuro y frío túnel. Un ligero resplandor viene de Arriba.\n");
  SetIntBright(25);
  AddDetail(({"resplandor","arriba"}),
    "Parece que hay un hueco... Sin duda puedes salir por allí.\n");
  AddDetail("hueco",
    "Seguro que puedes salir por él.\n");
  AddExit("arriba",SF(haz_arriba));
  AddExit("sur","./pasadizo15");
}
