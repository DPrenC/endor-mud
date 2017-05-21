#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al este y oeste continúa el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino12"));
  AddExit("oeste", TBOSQUE("camino10"));
  AddExit("sur", TBOSQUE("bosque105"));
  AddExit("sudeste", TBOSQUE("bosque106"));
  AddExit("suroeste", TBOSQUE("bosque104"));
  AddExit("norte", TBOSQUE("bosque082"));
  AddExit("nordeste", TBOSQUE("bosque083"));
  AddExit("noroeste", TBOSQUE("bosque081"));
}
