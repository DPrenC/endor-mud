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
  AddExit("este", TBOSQUE("bosque265"));
  AddExit("oeste", TBOSQUE("bosque263"));
  AddExit("sur", TBOSQUE("bosque275"));
  AddExit("sudeste", TBOSQUE("bosque276"));
  AddExit("suroeste", TBOSQUE("bosque274"));
  AddExit("norte", TBOSQUE("bosque253"));
  AddExit("nordeste", TBOSQUE("bosque254"));
  AddExit("noroeste", TBOSQUE("bosque252"));
  ::salidas_cmd();
}
