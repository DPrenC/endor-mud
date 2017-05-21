#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  SetIntLong(W("Estás en una bifurcación. El camino se abre en tres "
  	"direcciones, nordeste, este, y sudeste.\n"));
  AddExit("este", ATB_C("cueva31"));
  AddExit("nordeste", ATB_C("cueva24"));
  AddExit("oeste", ATB_C("cueva22"));
  AddExit("sudeste", ATB_C("cueva38"));
}
