#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque140"));
  AddExit("oeste", TBOSQUE("bosque138"));
  AddExit("norte", TBOSQUE("bosque125"));
  AddExit("nordeste", TBOSQUE("bosque126"));
  AddExit("noroeste", TBOSQUE("bosque124"));
  ::salidas_cmd();
}
