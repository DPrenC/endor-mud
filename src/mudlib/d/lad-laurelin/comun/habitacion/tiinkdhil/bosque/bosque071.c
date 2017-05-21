#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque072"));
  AddExit("oeste", TBOSQUE("bosque070"));
  AddExit("sur", TBOSQUE("bosque084"));
  AddExit("sudeste", TBOSQUE("bosque085"));
  AddExit("suroeste", TBOSQUE("bosque083"));
  AddExit("norte", TBOSQUE("bosque055"));
  AddExit("nordeste", TBOSQUE("bosque056"));
  AddExit("noroeste", TBOSQUE("bosque054"));
  ::salidas_cmd();
}
