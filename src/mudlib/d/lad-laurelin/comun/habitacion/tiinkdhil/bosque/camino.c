/*
   Camino que une atbalnin con tiink
   Creado por Lonerwolf 09-11-00
*/


#include "path.h"
#include <wizlevels.h>
#include <nightday.h>


inherit LAD_ROOM_EX;

int cmd_clima()
{
  write(CHRONOS->QueryWeatherMsg());
  return 1;
}

int cmd_mirar(string que)
{
  if (que=="suelo")
  {
    write(CHRONOS->QueryGroundDesc());
    return 1;
  }
  if (que=="clima" || que=="tiempo")
    return cmd_clima();
  return 0;
}

create(){
  mixed s;
  string *f;

  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	       "túnel.\n"));
  SetIntShort("el camino atbalnin tiink");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("Camino Atbalnin-Tiink");
  SetIndoors(0);

  AddRoomCmd(({"mirar", "mi", "m"}), SF(cmd_mirar));
  AddRoomCmd("clima", SF(cmd_clima));
  SetServer(CHRONOS);
}
