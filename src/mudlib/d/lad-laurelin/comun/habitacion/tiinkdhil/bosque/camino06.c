#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al suroeste y este continúa el sendero.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino07"));
  AddExit("oeste", TBOSQUE("bosque080"));
  AddExit("sur", TBOSQUE("bosque091"));
  AddExit("sudeste", TBOSQUE("bosque092"));
  AddExit("suroeste", TBOSQUE("camino05"));
  AddExit("norte", TBOSQUE("bosque064"));
  AddExit("nordeste", TBOSQUE("bosque065"));
  AddExit("noroeste", TBOSQUE("bosque063"));
}
