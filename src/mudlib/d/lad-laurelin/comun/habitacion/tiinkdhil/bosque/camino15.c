#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que pareces estar dentro de un "
	"t�nel. Al este se encuentra la entrada la la ciudad de Tiink, "
        "mientras que al oeste contin�a el camino a Atbalnin.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TCSUELO("salida2"));
  AddExit("oeste", TBOSQUE("camino14"));
  AddExit("sur", TBOSQUE("bosque109"));
  AddExit("suroeste", TBOSQUE("bosque108"));
  AddExit("norte", TBOSQUE("bosque086"));
  AddExit("noroeste", TBOSQUE("bosque085"));
}
