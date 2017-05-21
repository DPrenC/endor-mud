#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque103"));
  AddExit("oeste", TBOSQUE("bosque101"));
  AddExit("sur", TBOSQUE("bosque116"));
  AddExit("sudeste", TBOSQUE("bosque117"));
  AddExit("suroeste", TBOSQUE("bosque115"));
  AddExit("norte", TBOSQUE("bosque093"));
  AddExit("nordeste", TBOSQUE("bosque094"));
  AddExit("noroeste", TBOSQUE("bosque092"));
  ::salidas_cmd();

}
