#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque088"));
  AddExit("sur", TBOSQUE("bosque095"));
  AddExit("sudeste", TBOSQUE("bosque096"));
  AddExit("norte", TBOSQUE("bosque075"));
  AddExit("nordeste", TBOSQUE("bosque076"));
  AddExit("noroeste", TBOSQUE("bosque074"));
  ::salidas_cmd();
}
