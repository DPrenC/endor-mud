#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al oeste y este continúa el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino14"));
  AddExit("oeste", TBOSQUE("camino12"));
  AddExit("sur", TBOSQUE("bosque107"));
  AddExit("sudeste", TBOSQUE("bosque108"));
  AddExit("suroeste", TBOSQUE("bosque106"));
  AddExit("norte", TBOSQUE("bosque084"));
  AddExit("nordeste", TBOSQUE("bosque085"));
  AddExit("noroeste", TBOSQUE("bosque083"));
}
