#include "path.h"
inherit TBOSQUE("aleat_bosque");

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque288"));
  AddExit("norte", TBOSQUE("bosque285"));
  AddExit("noroeste", TBOSQUE("bosque284"));
  ::salidas_cmd();
}
