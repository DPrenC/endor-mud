#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al suroeste y este contin�a el sendero.\n"));
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
