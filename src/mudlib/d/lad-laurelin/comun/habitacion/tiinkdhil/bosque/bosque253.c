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
  AddExit("este", TBOSQUE("bosque254"));
  AddExit("oeste", TBOSQUE("bosque252"));
  AddExit("sur", TBOSQUE("bosque264"));
  AddExit("sudeste", TBOSQUE("bosque265"));
  AddExit("suroeste", TBOSQUE("bosque263"));
  AddExit("norte", TBOSQUE("bosque242"));
  AddExit("nordeste", TBOSQUE("bosque243"));
  AddExit("noroeste", TBOSQUE("bosque241"));
  ::salidas_cmd();
}
