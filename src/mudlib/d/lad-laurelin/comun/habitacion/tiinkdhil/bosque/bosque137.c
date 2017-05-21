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
  AddExit("este", TBOSQUE("bosque228"));
  AddExit("oeste", TBOSQUE("bosque136"));
  AddExit("sur", TBOSQUE("bosque148"));
  AddExit("sudeste", TBOSQUE("bosque239"));
  AddExit("suroeste", TBOSQUE("bosque147"));
  AddExit("norte", TBOSQUE("bosque123"));
  AddExit("nordeste", TBOSQUE("bosque217"));
  AddExit("noroeste", TBOSQUE("bosque122"));
  ::salidas_cmd();
}
