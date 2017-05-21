#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque169"));
  AddExit("oeste", TBOSQUE("bosque167"));
  AddExit("sur", TBOSQUE("bosque173"));
  AddExit("sudeste", TBOSQUE("bosque174"));
  AddExit("suroeste", TBOSQUE("bosque172"));
  AddExit("norte", TBOSQUE("bosque163"));
  AddExit("nordeste", TBOSQUE("bosque164"));
  ::salidas_cmd();
}
