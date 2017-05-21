#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("norte");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque057"));
  AddExit("oeste", TBOSQUE("bosque055"));
  AddExit("sur", TBOSQUE("bosque072"));
  AddExit("sudeste", TBOSQUE("bosque073"));
  AddExit("suroeste", TBOSQUE("bosque071"));
  AddExit("norte", TBOSQUE("bosque040"));
  AddExit("nordeste", TBOSQUE("bosque041"));
  AddExit("noroeste", TBOSQUE("bosque039"));
  ::salidas_cmd();
}
