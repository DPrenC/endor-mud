#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("norte");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque052"));
  AddExit("oeste", TBOSQUE("bosque050"));
  AddExit("sur", TBOSQUE("bosque067"));
  AddExit("sudeste", TBOSQUE("bosque068"));
  AddExit("suroeste", TBOSQUE("bosque066"));
  AddExit("norte", TBOSQUE("bosque035"));
  AddExit("nordeste", TBOSQUE("bosque036"));
  AddExit("noroeste", TBOSQUE("bosque034"));
  ::salidas_cmd();
}
