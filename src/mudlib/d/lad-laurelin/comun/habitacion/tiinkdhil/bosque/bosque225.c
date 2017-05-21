#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque226"));
  AddExit("oeste", TBOSQUE("bosque224"));
  AddExit("sur", TBOSQUE("bosque236"));
  AddExit("sudeste", TBOSQUE("bosque237"));
  AddExit("suroeste", TBOSQUE("bosque235"));
  AddExit("norte", TBOSQUE("bosque214"));
  AddExit("nordeste", TBOSQUE("bosque215"));
  AddExit("noroeste", TBOSQUE("bosque213"));
  ::salidas_cmd();
}
