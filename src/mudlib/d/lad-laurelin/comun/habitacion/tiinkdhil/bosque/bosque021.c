#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque022"));
  AddExit("sur", TBOSQUE("bosque037"));
  AddExit("oeste", TBOSQUE("bosque020"));
  AddExit("sudeste", TBOSQUE("bosque038"));
  AddExit("suroeste", TBOSQUE("bosque036"));
  ::salidas_cmd();
}
