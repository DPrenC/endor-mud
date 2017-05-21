#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("norte");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque276"));
  AddExit("oeste", TBOSQUE("bosque274"));
  AddExit("norte", TBOSQUE("bosque264"));
  AddExit("nordeste", TBOSQUE("bosque265"));
  AddExit("noroeste", TBOSQUE("bosque263"));
  ::salidas_cmd();
}
