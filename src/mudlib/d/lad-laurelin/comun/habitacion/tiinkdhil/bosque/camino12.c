#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al oeste y este contin�a el sendero.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino13"));
  AddExit("oeste", TBOSQUE("camino11"));
  AddExit("sur", TBOSQUE("bosque106"));
  AddExit("sudeste", TBOSQUE("bosque107"));
  AddExit("suroeste", TBOSQUE("bosque105"));
  AddExit("norte", TBOSQUE("bosque083"));
  AddExit("nordeste", TBOSQUE("bosque084"));
  AddExit("noroeste", TBOSQUE("bosque082"));
}
