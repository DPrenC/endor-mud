#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque044"));
  AddExit("sur", TBOSQUE("bosque059"));
  AddExit("oeste", TBOSQUE("bosque042"));
  AddExit("norte", TBOSQUE("bosque027"));
  AddExit("sudeste", TBOSQUE("bosque060"));
  AddExit("suroeste", TBOSQUE("bosque058"));
  AddExit("nordeste", TBOSQUE("bosque028"));
  AddExit("noroeste", TBOSQUE("bosque026"));
  ::salidas_cmd();
}
