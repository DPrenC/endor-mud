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
  AddExit("este", TBOSQUE("bosque046"));
  AddExit("oeste", TBOSQUE("bosque044"));
  AddExit("sur", TBOSQUE("bosque061"));
  AddExit("sudeste", TBOSQUE("bosque062"));
  AddExit("suroeste", TBOSQUE("bosque060"));
  AddExit("norte", TBOSQUE("bosque029"));
  AddExit("nordeste", TBOSQUE("bosque030"));
  AddExit("noroeste", TBOSQUE("bosque028"));
  ::salidas_cmd();

}
