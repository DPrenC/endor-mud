#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("nordeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque274"));
  AddExit("oeste", TBOSQUE("bosque272"));
  AddExit("norte", TBOSQUE("bosque262"));
  AddExit("nordeste", TBOSQUE("bosque263"));
  AddExit("noroeste", TBOSQUE("bosque261"));
  ::salidas_cmd();
}
