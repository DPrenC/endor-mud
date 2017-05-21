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
  AddExit("este", TBOSQUE("bosque225"));
  AddExit("oeste", TBOSQUE("bosque223"));
  AddExit("sur", TBOSQUE("bosque235"));
  AddExit("sudeste", TBOSQUE("bosque236"));
  AddExit("suroeste", TBOSQUE("bosque234"));
  AddExit("norte", TBOSQUE("bosque213"));
  AddExit("nordeste", TBOSQUE("bosque214"));
  AddExit("noroeste", TBOSQUE("bosque212"));
  ::salidas_cmd();
}
