#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al suroeste y noreste contin�a el sendero.\n"));
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
