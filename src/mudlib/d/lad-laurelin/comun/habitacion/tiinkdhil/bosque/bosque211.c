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
  AddExit("este", TBOSQUE("bosque212"));
  AddExit("oeste", TBOSQUE("bosque210"));
  AddExit("sur", TBOSQUE("bosque222"));
  AddExit("sudeste", TBOSQUE("bosque223"));
  AddExit("suroeste", TBOSQUE("bosque221"));
  AddExit("norte", TBOSQUE("bosque203"));
  AddExit("nordeste", TBOSQUE("bosque204"));
  AddExit("noroeste", TBOSQUE("bosque202"));
  ::salidas_cmd();
}
