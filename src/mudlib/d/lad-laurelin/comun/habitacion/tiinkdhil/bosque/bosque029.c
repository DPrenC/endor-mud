#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque030"));
  AddExit("sur", TBOSQUE("bosque045"));
  AddExit("oeste", TBOSQUE("bosque028"));
  AddExit("norte", TBOSQUE("bosque013"));
  AddExit("sudeste", TBOSQUE("bosque046"));
  AddExit("suroeste", TBOSQUE("bosque044"));
  AddExit("noroeste", TBOSQUE("bosque012"));
  AddExit("nordeste", TBOSQUE("bosque014"));
  ::salidas_cmd();
}
