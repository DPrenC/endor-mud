#include "path.h"
inherit TBOSQUE("camino");

create(){
  ::create();
  SetIntLong(W("Est� el el camino que une Atbalnin con la cuidad de tiink. "
	"Hay tantos �rboles  y vegetaci�n que parees estar dentro de un "
	"t�nel. Al suroeste y nordeste contin�a el camino.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque111"));
  AddExit("oeste", TBOSQUE("bosque110"));
  AddExit("sur", TBOSQUE("bosque124"));
  AddExit("sudeste", TBOSQUE("bosque125"));
  AddExit("suroeste", TBOSQUE("camino01"));
  AddExit("norte", TBOSQUE("bosque097"));
  AddExit("nordeste", TBOSQUE("camino03"));
  AddExit("noroeste", TBOSQUE("bosque096"));
}
