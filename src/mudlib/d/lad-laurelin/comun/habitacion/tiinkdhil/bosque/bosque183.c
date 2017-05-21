#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
//  AddExit("este", TBOSQUE("gigantes2"));
  AddExit("oeste", TBOSQUE("bosque182"));
  AddExit("sur", TBOSQUE("bosque192"));
  AddExit("suroeste", TBOSQUE("bosque191"));
  ::salidas_cmd();
}
