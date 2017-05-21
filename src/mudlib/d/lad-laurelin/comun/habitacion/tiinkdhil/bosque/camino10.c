#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al noroeste y este continúa el sendero.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino11"));
  AddExit("oeste", TBOSQUE("bosque094"));
  AddExit("sur", TBOSQUE("bosque104"));
  AddExit("sudeste", TBOSQUE("bosque105"));
  AddExit("suroeste", TBOSQUE("bosque103"));
  AddExit("norte", TBOSQUE("bosque081"));
  AddExit("nordeste", TBOSQUE("bosque082"));
  AddExit("noroeste", TBOSQUE("camino09"));
}
