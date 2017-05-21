#include "./path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Está el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos árboles  y vegetación que parees estar dentro de un "
	"túnel. Al suroeste entras en la ciudad de atbalnin, mientras que"
        " al noreste continúa el sendero a tiink\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque124"));
  AddExit("sudeste", TBOSQUE("bosque138"));
  AddExit("norte", TBOSQUE("bosque110"));
  AddExit("nordeste", TBOSQUE("camino02"));
  AddExit("suroeste", ATB_CI("ciudad33"));
  ::salidas_cmd();
}
