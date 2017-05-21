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
  AddExit("este", TBOSQUE("bosque045"));
  AddExit("sur", TBOSQUE("bosque060"));
  AddExit("oeste", TBOSQUE("bosque043"));
  AddExit("norte", TBOSQUE("bosque028"));
  AddExit("sudeste", TBOSQUE("bosque061"));
  AddExit("suroeste", TBOSQUE("bosque059"));
  AddExit("nordeste", TBOSQUE("bosque029"));
  AddExit("noroeste", TBOSQUE("bosque027"));
  ::salidas_cmd();
}
