#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al noroeste y este contin�a el sendero.\n"));
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
