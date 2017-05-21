#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque184"));
  AddExit("oeste", TBOSQUE("bosque072"));
  AddExit("sur", TBOSQUE("bosque086"));
  AddExit("suroeste", TBOSQUE("bosque085"));
  AddExit("norte", TBOSQUE("bosque057"));
  AddExit("nordeste", TBOSQUE("bosque175"));
  AddExit("noroeste", TBOSQUE("bosque056"));
  ::salidas_cmd();
}
