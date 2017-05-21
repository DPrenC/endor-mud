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
  AddExit("este", TBOSQUE("bosque029"));
  AddExit("sur", TBOSQUE("bosque044"));
  AddExit("oeste", TBOSQUE("bosque027"));
  AddExit("norte", TBOSQUE("bosque012"));
  AddExit("sudeste", TBOSQUE("bosque045"));
  AddExit("suroeste", TBOSQUE("bosque043"));
  AddExit("noroeste", TBOSQUE("bosque011"));
  AddExit("nordeste", TBOSQUE("bosque013"));
  ::salidas_cmd();
}
