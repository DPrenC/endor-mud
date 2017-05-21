#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque192"));
  AddExit("oeste", TBOSQUE("bosque190"));
  AddExit("sur", TBOSQUE("bosque197"));
  AddExit("sudeste", TBOSQUE("bosque198"));
  AddExit("suroeste", TBOSQUE("bosque196"));
  AddExit("norte", TBOSQUE("bosque182"));
  AddExit("nordeste", TBOSQUE("bosque183"));
  AddExit("noroeste", TBOSQUE("bosque181"));
  ::salidas_cmd();
}
