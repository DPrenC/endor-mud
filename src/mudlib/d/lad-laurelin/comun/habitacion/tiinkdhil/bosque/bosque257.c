#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque258"));
  AddExit("oeste", TBOSQUE("bosque256"));
  AddExit("sur", TBOSQUE("bosque268"));
  AddExit("sudeste", TBOSQUE("bosque269"));
  AddExit("suroeste", TBOSQUE("bosque267"));
  AddExit("norte", TBOSQUE("bosque246"));
  AddExit("nordeste", TBOSQUE("bosque247"));
  AddExit("noroeste", TBOSQUE("bosque245"));
  ::salidas_cmd();
}
