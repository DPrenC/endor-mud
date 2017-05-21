#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque266"));
  AddExit("oeste", TBOSQUE("bosque264"));
  AddExit("sur", TBOSQUE("bosque276"));
  AddExit("sudeste", TBOSQUE("bosque277"));
  AddExit("suroeste", TBOSQUE("bosque275"));
  AddExit("norte", TBOSQUE("bosque254"));
  AddExit("nordeste", TBOSQUE("bosque255"));
  AddExit("noroeste", TBOSQUE("bosque253"));
  ::salidas_cmd();
}
