#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino03"));
  AddExit("oeste", TBOSQUE("bosque096"));
  AddExit("sur", TBOSQUE("camino02"));
  AddExit("sudeste", TBOSQUE("bosque111"));
  AddExit("suroeste", TBOSQUE("bosque110"));
  AddExit("norte", TBOSQUE("bosque089"));
  AddExit("nordeste", TBOSQUE("bosque090"));
  AddExit("noroeste", TBOSQUE("bosque088"));
  ::salidas_cmd();
}
