#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noreste");
  SetPathToGigants("suroeste");
  SetIntLong(W("Est�s en un bosque bastante frondoso, donde la "
	"vegetaci�n casi cierra el camino. Hacia el nordeste ves una cueva.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque019"));
  AddExit("sur", TBOSQUE("bosque035"));
  AddExit("oeste", TBOSQUE("bosque017"));
  AddExit("sudeste", TBOSQUE("bosque036"));
  AddExit("suroeste", TBOSQUE("bosque034"));
//   AddExit("nordeste", TBOSQUE("trolls"));
  ::salidas_cmd();
}
