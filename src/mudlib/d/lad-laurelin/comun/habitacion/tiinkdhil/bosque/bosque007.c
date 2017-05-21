#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("sudeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque008"));
  AddExit("oeste", TBOSQUE("bosque006"));
  AddExit("sur", TBOSQUE("bosque012"));
  AddExit("sudeste", TBOSQUE("bosque013"));
  AddExit("suroeste", TBOSQUE("bosque011"));
  AddExit("norte", TBOSQUE("bosque003"));
  AddExit("nordeste", TBOSQUE("bosque004"));
  AddExit("noroeste", TBOSQUE("bosque002"));
  ::salidas_cmd();
}
