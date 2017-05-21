#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque224"));
  AddExit("oeste", TBOSQUE("bosque222"));
  AddExit("sur", TBOSQUE("bosque234"));
  AddExit("sudeste", TBOSQUE("bosque235"));
  AddExit("suroeste", TBOSQUE("bosque233"));
  AddExit("norte", TBOSQUE("bosque212"));
  AddExit("nordeste", TBOSQUE("bosque213"));
  AddExit("noroeste", TBOSQUE("bosque211"));
  ::salidas_cmd();
}
