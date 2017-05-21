
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
  SetIntLong("Pinos y abetos se cruzan en tu camino. Conejos y algún que "
  		"otro zorro te husmean con curiosidad y se alejan.\n");

  AddExit("sur",ALULAGO("bosque/bosque14"));
  AddExit("este",ALULAGO("bosque/cabanya"));
  AddExit("sudeste",ALULAGO("bosque/bosque15"));
  AddExit("oeste",ALULAGO("bosque/cam3"));
}
