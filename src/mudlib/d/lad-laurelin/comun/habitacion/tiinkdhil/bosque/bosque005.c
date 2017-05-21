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
  AddExit("este", TBOSQUE("bosque006"));
  AddExit("sur", TBOSQUE("bosque010"));
  AddExit("sudeste", TBOSQUE("bosque011"));
  AddExit("nordeste", TBOSQUE("bosque002"));
  ::salidas_cmd();
}
