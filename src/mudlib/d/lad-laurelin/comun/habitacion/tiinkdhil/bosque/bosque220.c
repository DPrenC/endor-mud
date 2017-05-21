#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque221"));
  AddExit("oeste", TBOSQUE("bosque219"));
  AddExit("sur", TBOSQUE("bosque231"));
  AddExit("sudeste", TBOSQUE("bosque232"));
  AddExit("suroeste", TBOSQUE("bosque230"));
  AddExit("norte", TBOSQUE("bosque209"));
  AddExit("nordeste", TBOSQUE("bosque210"));
  ::salidas_cmd();
}
