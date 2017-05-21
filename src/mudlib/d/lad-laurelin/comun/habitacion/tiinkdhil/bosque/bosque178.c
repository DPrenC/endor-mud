#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque179"));
  AddExit("oeste", TBOSQUE("bosque177"));
  AddExit("sur", TBOSQUE("bosque187"));
  AddExit("sudeste", TBOSQUE("bosque188"));
  AddExit("suroeste", TBOSQUE("bosque186"));
  AddExit("noroeste", TBOSQUE("bosque173"));
  ::salidas_cmd();
}
