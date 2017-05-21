#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque123"));
  AddExit("oeste", TBOSQUE("bosque121"));
  AddExit("sur", TBOSQUE("bosque136"));
  AddExit("sudeste", TBOSQUE("bosque137"));
  AddExit("suroeste", TBOSQUE("bosque135"));
  AddExit("norte", TBOSQUE("bosque108"));
  AddExit("nordeste", TBOSQUE("bosque109"));
  AddExit("noroeste", TBOSQUE("bosque107"));
  ::salidas_cmd();

}
