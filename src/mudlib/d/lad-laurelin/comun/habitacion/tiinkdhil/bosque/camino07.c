#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al este y oeste contin�a el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino08"));
  AddExit("oeste", TBOSQUE("camino06"));
  AddExit("sur", TBOSQUE("bosque092"));
  AddExit("sudeste", TBOSQUE("bosque093"));
  AddExit("suroeste", TBOSQUE("bosque091"));
  AddExit("norte", TBOSQUE("bosque065"));
  AddExit("nordeste", TBOSQUE("bosque066"));
  AddExit("noroeste", TBOSQUE("bosque064"));
}
