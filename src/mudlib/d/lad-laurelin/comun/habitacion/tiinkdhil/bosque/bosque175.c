#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque176"));
  AddExit("oeste", TBOSQUE("bosque057"));
  AddExit("sur", TBOSQUE("bosque184"));
  AddExit("sudeste", TBOSQUE("bosque185"));
  AddExit("suroeste", TBOSQUE("bosque073"));
  AddExit("norte", TBOSQUE("bosque171"));
  AddExit("nordeste", TBOSQUE("bosque172"));
  AddExit("noroeste", TBOSQUE("bosque041"));
  ::salidas_cmd();
}
