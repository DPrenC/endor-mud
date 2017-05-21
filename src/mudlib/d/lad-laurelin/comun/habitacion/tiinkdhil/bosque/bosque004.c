#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("sur");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque003"));
  AddExit("sur", TBOSQUE("bosque008"));
  AddExit("sudeste", TBOSQUE("bosque009"));
  AddExit("suroeste", TBOSQUE("bosque007"));
  AddExit("norte", TBOSQUE("bosque001"));
  AddExit("noroeste", TBOSQUE("bosque000"));
  ::salidas_cmd();
}

