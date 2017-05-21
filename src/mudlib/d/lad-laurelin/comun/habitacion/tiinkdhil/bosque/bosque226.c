#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque227"));
  AddExit("oeste", TBOSQUE("bosque225"));
  AddExit("sur", TBOSQUE("bosque237"));
  AddExit("sudeste", TBOSQUE("bosque238"));
  AddExit("suroeste", TBOSQUE("bosque236"));
  AddExit("norte", TBOSQUE("bosque215"));
  AddExit("nordeste", TBOSQUE("bosque216"));
  AddExit("noroeste", TBOSQUE("bosque214"));
  ::salidas_cmd();
}
