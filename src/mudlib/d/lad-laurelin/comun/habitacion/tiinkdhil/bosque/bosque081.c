#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque082"));
  AddExit("oeste", TBOSQUE("camino09"));
  AddExit("sur", TBOSQUE("camino10"));
  AddExit("sudeste", TBOSQUE("camino11"));
  AddExit("suroeste", TBOSQUE("bosque094"));
  AddExit("norte", TBOSQUE("bosque068"));
  AddExit("nordeste", TBOSQUE("bosque069"));
  AddExit("noroeste", TBOSQUE("bosque067"));
  ::salidas_cmd();
}
