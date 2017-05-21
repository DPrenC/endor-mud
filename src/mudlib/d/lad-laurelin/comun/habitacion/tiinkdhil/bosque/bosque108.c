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
  AddExit("este", TBOSQUE("bosque109"));
  AddExit("oeste", TBOSQUE("bosque107"));
  AddExit("sur", TBOSQUE("bosque122"));
  AddExit("sudeste", TBOSQUE("bosque123"));
  AddExit("suroeste", TBOSQUE("bosque121"));
  AddExit("norte", TBOSQUE("camino14"));
  AddExit("nordeste", TBOSQUE("camino15"));
  AddExit("noroeste", TBOSQUE("camino13"));
  ::salidas_cmd();

}
