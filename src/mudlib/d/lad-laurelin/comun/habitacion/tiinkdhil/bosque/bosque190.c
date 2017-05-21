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
  AddExit("este", TBOSQUE("bosque191"));
  AddExit("oeste", TBOSQUE("bosque189"));
  AddExit("sur", TBOSQUE("bosque196"));
  AddExit("sudeste", TBOSQUE("bosque197"));
  AddExit("suroeste", TBOSQUE("bosque195"));
  AddExit("norte", TBOSQUE("bosque181"));
  AddExit("nordeste", TBOSQUE("bosque182"));
  AddExit("noroeste", TBOSQUE("bosque180"));
  ::salidas_cmd();
}
