#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque054"));
  AddExit("oeste", TBOSQUE("bosque052"));
  AddExit("sur", TBOSQUE("bosque069"));
  AddExit("sudeste", TBOSQUE("bosque070"));
  AddExit("suroeste", TBOSQUE("bosque068"));
  AddExit("norte", TBOSQUE("bosque037"));
  AddExit("nordeste", TBOSQUE("bosque038"));
  AddExit("noroeste", TBOSQUE("bosque036"));
  ::salidas_cmd();
}
