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
  AddExit("oeste", TBOSQUE("bosque169"));
  AddExit("suroeste", TBOSQUE("bosque174"));
  AddExit("norte", TBOSQUE("bosque165"));
  AddExit("noroeste", TBOSQUE("bosque164"));
  ::salidas_cmd();
}
