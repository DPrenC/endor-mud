#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("sudeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque004"));
  AddExit("oeste", TBOSQUE("bosque002"));
  AddExit("sur", TBOSQUE("bosque007"));
  AddExit("sudeste", TBOSQUE("bosque008"));
  AddExit("suroeste", TBOSQUE("bosque006"));
  AddExit("norte", TBOSQUE("bosque000"));
  AddExit("nordeste", TBOSQUE("bosque001"));
  ::salidas_cmd();
}
