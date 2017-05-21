#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("noroeste");
  SetPathToGigants("sudeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque173"));
  AddExit("oeste", TBOSQUE("bosque171"));
  AddExit("sur", TBOSQUE("bosque176"));
  AddExit("sudeste", TBOSQUE("bosque177"));
  AddExit("suroeste", TBOSQUE("bosque175"));
  AddExit("norte", TBOSQUE("bosque167"));
  AddExit("nordeste", TBOSQUE("bosque168"));
  AddExit("noroeste", TBOSQUE("bosque166"));
  ::salidas_cmd();
}
