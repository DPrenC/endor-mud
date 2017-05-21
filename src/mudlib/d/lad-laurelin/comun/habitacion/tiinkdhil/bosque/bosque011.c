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
  AddExit("este", TBOSQUE("bosque012"));
  AddExit("oeste", TBOSQUE("bosque010"));
  AddExit("sur", TBOSQUE("bosque027"));
  AddExit("sudeste", TBOSQUE("bosque028"));
  AddExit("suroeste", TBOSQUE("bosque026"));
  AddExit("norte", TBOSQUE("bosque006"));
  AddExit("nordeste", TBOSQUE("bosque007"));
  AddExit("noroeste", TBOSQUE("bosque005"));
  ::salidas_cmd();
}
