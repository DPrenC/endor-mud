#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al oeste y este contin�a el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino15"));
  AddExit("oeste", TBOSQUE("camino13"));
  AddExit("sur", TBOSQUE("bosque108"));
  AddExit("sudeste", TBOSQUE("bosque109"));
  AddExit("suroeste", TBOSQUE("bosque107"));
  AddExit("norte", TBOSQUE("bosque085"));
  AddExit("nordeste", TBOSQUE("bosque086"));
  AddExit("noroeste", TBOSQUE("bosque084"));
}
