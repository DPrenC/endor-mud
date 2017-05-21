#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque069"));
  AddExit("oeste", TBOSQUE("bosque067"));
  AddExit("sur", TBOSQUE("bosque081"));
  AddExit("sudeste", TBOSQUE("bosque082"));
  AddExit("suroeste", TBOSQUE("camino09"));
  AddExit("norte", TBOSQUE("bosque052"));
  AddExit("nordeste", TBOSQUE("bosque053"));
  AddExit("noroeste", TBOSQUE("bosque051"));
  ::salidas_cmd();
}
