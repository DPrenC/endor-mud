#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque185"));
  AddExit("oeste", TBOSQUE("bosque073"));
  AddExit("suroeste", TBOSQUE("bosque086"));
  AddExit("norte", TBOSQUE("bosque175"));
  AddExit("nordeste", TBOSQUE("bosque176"));
  AddExit("noroeste", TBOSQUE("bosque057"));
  ::salidas_cmd();
}
