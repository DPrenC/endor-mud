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
  AddExit("este", TBOSQUE("bosque248"));
  AddExit("oeste", TBOSQUE("bosque246"));
  AddExit("sur", TBOSQUE("bosque258"));
  AddExit("sudeste", TBOSQUE("bosque259"));
  AddExit("suroeste", TBOSQUE("bosque257"));
  AddExit("norte", TBOSQUE("bosque236"));
  AddExit("nordeste", TBOSQUE("bosque237"));
  AddExit("noroeste", TBOSQUE("bosque235"));
  ::salidas_cmd();
}
