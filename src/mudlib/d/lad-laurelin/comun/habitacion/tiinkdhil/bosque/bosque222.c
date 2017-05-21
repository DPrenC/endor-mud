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
  AddExit("este", TBOSQUE("bosque223"));
  AddExit("oeste", TBOSQUE("bosque221"));
  AddExit("sur", TBOSQUE("bosque233"));
  AddExit("sudeste", TBOSQUE("bosque234"));
  AddExit("suroeste", TBOSQUE("bosque232"));
  AddExit("norte", TBOSQUE("bosque211"));
  AddExit("nordeste", TBOSQUE("bosque212"));
  AddExit("noroeste", TBOSQUE("bosque210"));
  ::salidas_cmd();
}
