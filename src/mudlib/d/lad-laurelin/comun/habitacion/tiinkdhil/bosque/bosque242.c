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
  AddExit("este", TBOSQUE("bosque243"));
  AddExit("oeste", TBOSQUE("bosque241"));
  AddExit("sur", TBOSQUE("bosque253"));
  AddExit("sudeste", TBOSQUE("bosque254"));
  AddExit("suroeste", TBOSQUE("bosque252"));
  AddExit("norte", TBOSQUE("bosque231"));
  AddExit("nordeste", TBOSQUE("bosque232"));
  AddExit("noroeste", TBOSQUE("bosque230"));
  ::salidas_cmd();
}
