#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque096"));
  AddExit("sudeste", TBOSQUE("bosque110"));
  AddExit("norte", TBOSQUE("bosque087"));
  AddExit("nordeste", TBOSQUE("bosque088"));
  ::salidas_cmd();
}
