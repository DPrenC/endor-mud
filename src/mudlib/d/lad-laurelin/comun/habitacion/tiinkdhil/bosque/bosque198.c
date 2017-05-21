#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque199"));
  AddExit("oeste", TBOSQUE("bosque197"));
  AddExit("sur", TBOSQUE("bosque206"));
  AddExit("sudeste", TBOSQUE("bosque207"));
  AddExit("suroeste", TBOSQUE("bosque205"));
  AddExit("norte", TBOSQUE("bosque192"));
  AddExit("noroeste", TBOSQUE("bosque191"));
  ::salidas_cmd();
}
