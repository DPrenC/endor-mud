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
  AddExit("este", TBOSQUE("bosque151"));
  AddExit("oeste", TBOSQUE("bosque149"));
  AddExit("sur", TBOSQUE("bosque155"));
  AddExit("sudeste", TBOSQUE("bosque156"));
  AddExit("suroeste", TBOSQUE("bosque154"));
  AddExit("norte", TBOSQUE("bosque145"));
  AddExit("nordeste", TBOSQUE("bosque146"));
  AddExit("noroeste", TBOSQUE("bosque144"));
  ::salidas_cmd();
}
