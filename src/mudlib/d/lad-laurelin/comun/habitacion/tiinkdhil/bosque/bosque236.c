#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque237"));
  AddExit("oeste", TBOSQUE("bosque235"));
  AddExit("sur", TBOSQUE("bosque247"));
  AddExit("sudeste", TBOSQUE("bosque248"));
  AddExit("suroeste", TBOSQUE("bosque246"));
  AddExit("norte", TBOSQUE("bosque225"));
  AddExit("nordeste", TBOSQUE("bosque226"));
  AddExit("noroeste", TBOSQUE("bosque224"));
  ::salidas_cmd();
}
