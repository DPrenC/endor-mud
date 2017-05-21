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
  AddExit("este", TBOSQUE("bosque203"));
  AddExit("oeste", TBOSQUE("bosque201"));
  AddExit("sur", TBOSQUE("bosque210"));
  AddExit("sudeste", TBOSQUE("bosque211"));
  AddExit("suroeste", TBOSQUE("bosque209"));
  AddExit("norte", TBOSQUE("bosque194"));
  AddExit("nordeste", TBOSQUE("bosque195"));
  AddExit("noroeste", TBOSQUE("bosque193"));
  ::salidas_cmd();
}
