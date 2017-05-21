#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al suroeste y este continúa el sendero.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino05"));
  AddExit("oeste", TBOSQUE("bosque090"));
  AddExit("sur", TBOSQUE("bosque098"));
  AddExit("sudeste", TBOSQUE("bosque099"));
  AddExit("suroeste", TBOSQUE("camino03"));
  AddExit("norte", TBOSQUE("bosque079"));
  AddExit("nordeste", TBOSQUE("bosque080"));
  AddExit("noroeste", TBOSQUE("bosque078"));
}
