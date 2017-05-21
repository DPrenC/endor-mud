#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque215"));
  AddExit("sur", TBOSQUE("bosque227"));
  AddExit("suroeste", TBOSQUE("bosque226"));
  AddExit("norte", TBOSQUE("bosque208"));
  AddExit("noroeste", TBOSQUE("bosque207"));
  ::salidas_cmd();
}
