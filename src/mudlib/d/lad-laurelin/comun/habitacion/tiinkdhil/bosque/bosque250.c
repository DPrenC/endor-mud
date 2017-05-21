#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque251"));
  AddExit("oeste", TBOSQUE("bosque153"));
  AddExit("sur", TBOSQUE("bosque261"));
  AddExit("sudeste", TBOSQUE("bosque262"));
  AddExit("suroeste", TBOSQUE("bosque158"));
  AddExit("norte", TBOSQUE("bosque239"));
  AddExit("nordeste", TBOSQUE("bosque240"));
  AddExit("noroeste", TBOSQUE("bosque148"));
  ::salidas_cmd();
}
