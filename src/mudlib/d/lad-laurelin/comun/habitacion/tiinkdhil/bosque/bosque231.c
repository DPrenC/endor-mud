#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("norte");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque232"));
  AddExit("oeste", TBOSQUE("bosque230"));
  AddExit("sur", TBOSQUE("bosque242"));
  AddExit("sudeste", TBOSQUE("bosque243"));
  AddExit("suroeste", TBOSQUE("bosque241"));
  AddExit("norte", TBOSQUE("bosque220"));
  AddExit("nordeste", TBOSQUE("bosque221"));
  AddExit("noroeste", TBOSQUE("bosque219"));
  ::salidas_cmd();
}
