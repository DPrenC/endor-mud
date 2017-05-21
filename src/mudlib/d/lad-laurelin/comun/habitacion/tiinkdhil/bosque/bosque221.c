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
  AddExit("este", TBOSQUE("bosque222"));
  AddExit("oeste", TBOSQUE("bosque220"));
  AddExit("sur", TBOSQUE("bosque232"));
  AddExit("sudeste", TBOSQUE("bosque233"));
  AddExit("suroeste", TBOSQUE("bosque231"));
  AddExit("norte", TBOSQUE("bosque210"));
  AddExit("nordeste", TBOSQUE("bosque211"));
  AddExit("noroeste", TBOSQUE("bosque209"));
  ::salidas_cmd();
}
