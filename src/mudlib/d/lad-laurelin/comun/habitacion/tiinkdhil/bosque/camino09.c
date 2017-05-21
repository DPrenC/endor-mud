#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al oeste y sudeste continúa el sendero.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque081"));
  AddExit("oeste", TBOSQUE("camino08"));
  AddExit("sur", TBOSQUE("bosque094"));
  AddExit("sudeste", TBOSQUE("camino10"));
  AddExit("suroeste", TBOSQUE("bosque093"));
  AddExit("norte", TBOSQUE("bosque067"));
  AddExit("nordeste", TBOSQUE("bosque068"));
  AddExit("noroeste", TBOSQUE("bosque066"));
}
