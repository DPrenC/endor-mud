#include "./path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al suroeste entras en la ciudad de atbalnin, mientras que"
        " al noreste contin�a el sendero a tiink\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque124"));
  AddExit("sudeste", TBOSQUE("bosque138"));
  AddExit("norte", TBOSQUE("bosque110"));
  AddExit("nordeste", TBOSQUE("camino02"));
  AddExit("suroeste", ATB_CI("ciudad33"));
  ::salidas_cmd();
}
