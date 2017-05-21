#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque122"));
  AddExit("oeste", TBOSQUE("bosque120"));
  AddExit("sur", TBOSQUE("bosque135"));
  AddExit("sudeste", TBOSQUE("bosque136"));
  AddExit("suroeste", TBOSQUE("bosque134"));
  AddExit("norte", TBOSQUE("bosque107"));
  AddExit("nordeste", TBOSQUE("bosque108"));
  AddExit("noroeste", TBOSQUE("bosque106"));
  ::salidas_cmd();
}
