#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al suroeste y noreste continúa el sendero.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque097"));
  AddExit("oeste", TBOSQUE("bosque098"));
  AddExit("sur", TBOSQUE("bosque111"));
  AddExit("sudeste", TBOSQUE("bosque112"));
  AddExit("suroeste", TBOSQUE("camino02"));
  AddExit("norte", TBOSQUE("bosque090"));
  AddExit("nordeste", TBOSQUE("camino04"));
  AddExit("noroeste", TBOSQUE("bosque089"));
}
