#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque181"));
  AddExit("oeste", TBOSQUE("bosque179"));
  AddExit("sur", TBOSQUE("bosque189"));
  AddExit("sudeste", TBOSQUE("bosque190"));
  AddExit("suroeste", TBOSQUE("bosque188"));
  ::salidas_cmd();
}
