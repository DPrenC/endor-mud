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
  AddExit("este", TBOSQUE("bosque028"));
  AddExit("sur", TBOSQUE("bosque043"));
  AddExit("oeste", TBOSQUE("bosque026"));
  AddExit("norte", TBOSQUE("bosque011"));
  AddExit("sudeste", TBOSQUE("bosque044"));
  AddExit("suroeste", TBOSQUE("bosque042"));
  AddExit("noroeste", TBOSQUE("bosque010"));
  AddExit("nordeste", TBOSQUE("bosque012"));
  ::salidas_cmd();
}
