
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("Observas pinos y abetos por doquier. Descubres una madriguera.\n");
  AddDetail(({"madriguera"}),"Por su forma crees que es la madriguera de un conejo.\n");

  AddExit("norte",ALULAGO("bosque/bosque8"));
  AddExit("este",ALULAGO("bosque/bosque15"));
}
