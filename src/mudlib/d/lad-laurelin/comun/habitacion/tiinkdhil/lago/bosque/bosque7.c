
#include <rooms.h>
#include <nightday.h>
#include <properties.h>
#include "path.h"
inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("El aire aqui es seco y no huele a nada especial.\n");
  SetIntNoise("Escuchas el golpeteo del aire en tus orejas.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("Aunque antaño era un ruidoso bosque, ahora los únicos habitantes "
  		"de esta zona es la maleza y algún bicho asqueroso que huye a tu paso.\n");

  AddExit("norte",ALULAGO("bosque/bosque2"));
  AddExit("sur",ALULAGO("bosque/bosque13"));
  AddExit("este",ALULAGO("bosque/cam3"));
  AddExit("oeste",ALULAGO("bosque/bosque6"));
}
