#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al oeste y este contin�a el camino.\n"));
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
