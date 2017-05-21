#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("norte");
  SetPathToGigants("suroeste");
  SetIntLong(W("Estás en un bosque bastante frondoso, donde la "
	"vegetación casi cierra el camino. Hacia el norte ves una cueva.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque020"));
  AddExit("sur", TBOSQUE("bosque035"));
  AddExit("oeste", TBOSQUE("bosque018"));
//   AddExit("norte", TBOSQUE("trolls"));

  AddExit("sudeste", TBOSQUE("bosque036"));
  AddExit("suroeste", TBOSQUE("bosque034"));
  ::salidas_cmd();
}
