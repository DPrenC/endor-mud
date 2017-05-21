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
  AddExit("este", TBOSQUE("bosque180"));
  AddExit("oeste", TBOSQUE("bosque178"));
  AddExit("sur", TBOSQUE("bosque188"));
  AddExit("sudeste", TBOSQUE("bosque189"));
  AddExit("suroeste", TBOSQUE("bosque187"));
  ::salidas_cmd();
}
