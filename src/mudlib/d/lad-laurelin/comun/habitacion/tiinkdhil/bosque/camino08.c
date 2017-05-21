#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al oeste y este continúa el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino09"));
  AddExit("oeste", TBOSQUE("camino07"));
  AddExit("sur", TBOSQUE("bosque093"));
  AddExit("sudeste", TBOSQUE("bosque094"));
  AddExit("suroeste", TBOSQUE("bosque092"));
  AddExit("norte", TBOSQUE("bosque066"));
  AddExit("nordeste", TBOSQUE("bosque067"));
  AddExit("noroeste", TBOSQUE("bosque065"));
}
