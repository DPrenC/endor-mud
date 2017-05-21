#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque170"));
  AddExit("oeste", TBOSQUE("bosque168"));
  AddExit("sur", TBOSQUE("bosque174"));
  AddExit("suroeste", TBOSQUE("bosque173"));
  AddExit("norte", TBOSQUE("bosque164"));
  AddExit("nordeste", TBOSQUE("bosque165"));
  AddExit("noroeste", TBOSQUE("bosque163"));
  ::salidas_cmd();
}
