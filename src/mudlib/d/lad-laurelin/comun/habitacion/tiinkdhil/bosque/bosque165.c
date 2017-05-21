#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("suroeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque164"));
  AddExit("sur", TBOSQUE("bosque170"));
  AddExit("suroeste", TBOSQUE("bosque169"));
//  AddExit("norte", TBOSQUE("valle"));
  ::salidas_cmd();
}
