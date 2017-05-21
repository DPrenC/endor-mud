#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("noroeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque177"));
  AddExit("oeste", TBOSQUE("bosque175"));
  AddExit("sur", TBOSQUE("bosque185"));
  AddExit("sudeste", TBOSQUE("bosque186"));
  AddExit("suroeste", TBOSQUE("bosque184"));
  AddExit("norte", TBOSQUE("bosque172"));
  AddExit("nordeste", TBOSQUE("bosque173"));
  AddExit("noroeste", TBOSQUE("bosque171"));
  ::salidas_cmd();
}
