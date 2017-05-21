#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("suroeste");
  SetIntLong(W("Estás en un bosque bastante frondoso, donde la "
	"vegetación casi cierra el camino. Hacia el noroeste ves una cueva.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque021"));
  AddExit("sur", TBOSQUE("bosque036"));
  AddExit("oeste", TBOSQUE("bosque019"));
  AddExit("sudeste", TBOSQUE("bosque037"));
  AddExit("suroeste", TBOSQUE("bosque035"));
//  AddExit("noroeste", TBOSQUE("trolls"));
  ::salidas_cmd();
}
