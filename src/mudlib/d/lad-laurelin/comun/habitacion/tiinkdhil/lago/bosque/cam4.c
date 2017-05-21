
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  SetIntShort("un camino empedrado");
  SetIntLong("Continúas en el camino. Te acercas al norte de la cordillera que "
  		"rodea este valle. La tupida vegetación que hay a ambos lados del "
  		"camino sólo te permite moverte hacia el oeste.\n");

  AddDetail(({"vegetacion","vegetación"}),"Principalmente es maleza llena de "
  		"pinchos y arbustos largos y frondosos.\n");

  AddExit("norte",ALULAGO("bosque/cam5"));
  AddExit("sur",ALULAGO("bosque/cam3"));
  AddExit("oeste",ALULAGO("bosque/bosque2"));
}