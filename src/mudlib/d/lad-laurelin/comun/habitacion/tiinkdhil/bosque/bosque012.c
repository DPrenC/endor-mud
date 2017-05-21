#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque013"));
  AddExit("oeste", TBOSQUE("bosque011"));
  AddExit("sur", TBOSQUE("bosque028"));
  AddExit("sudeste", TBOSQUE("bosque029"));
  AddExit("suroeste", TBOSQUE("bosque027"));
  AddExit("norte", TBOSQUE("bosque007"));
  AddExit("nordeste", TBOSQUE("bosque008"));
  AddExit("noroeste", TBOSQUE("bosque006"));
  ::salidas_cmd();
}
