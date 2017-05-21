#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque051"));
  AddExit("oeste", TBOSQUE("bosque049"));
  AddExit("sur", TBOSQUE("bosque066"));
  AddExit("sudeste", TBOSQUE("bosque067"));
  AddExit("suroeste", TBOSQUE("bosque065"));
  AddExit("norte", TBOSQUE("bosque034"));
  AddExit("nordeste", TBOSQUE("bosque035"));
  AddExit("noroeste", TBOSQUE("bosque033"));
  ::salidas_cmd();
}
