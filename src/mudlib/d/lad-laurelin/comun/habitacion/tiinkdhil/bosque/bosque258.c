#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque259"));
  AddExit("oeste", TBOSQUE("bosque257"));
  AddExit("sur", TBOSQUE("bosque269"));
  AddExit("sudeste", TBOSQUE("bosque270"));
  AddExit("suroeste", TBOSQUE("bosque268"));
  AddExit("norte", TBOSQUE("bosque247"));
  AddExit("nordeste", TBOSQUE("bosque248"));
  AddExit("noroeste", TBOSQUE("bosque246"));
  ::salidas_cmd();
}
