#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al oeste y noreste contin�a el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque091"));
  AddExit("oeste", TBOSQUE("camino04"));
  AddExit("sur", TBOSQUE("bosque099"));
  AddExit("sudeste", TBOSQUE("bosque100"));
  AddExit("suroeste", TBOSQUE("bosque098"));
  AddExit("norte", TBOSQUE("bosque080"));
  AddExit("nordeste", TBOSQUE("camino06"));
  AddExit("noroeste", TBOSQUE("bosque079"));
}
