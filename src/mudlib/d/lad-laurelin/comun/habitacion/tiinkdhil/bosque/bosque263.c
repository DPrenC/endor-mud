#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque264"));
  AddExit("oeste", TBOSQUE("bosque262"));
  AddExit("sur", TBOSQUE("bosque274"));
  AddExit("sudeste", TBOSQUE("bosque275"));
  AddExit("suroeste", TBOSQUE("bosque273"));
  AddExit("norte", TBOSQUE("bosque252"));
  AddExit("nordeste", TBOSQUE("bosque253"));
  AddExit("noroeste", TBOSQUE("bosque251"));
  ::salidas_cmd();
}
