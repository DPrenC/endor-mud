#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque171"));
  AddExit("sur", TBOSQUE("bosque057"));
  AddExit("oeste", TBOSQUE("bosque040"));
  AddExit("norte", TBOSQUE("bosque025"));
  AddExit("sudeste", TBOSQUE("bosque175"));
  AddExit("suroeste", TBOSQUE("bosque056"));
  AddExit("nordeste", TBOSQUE("bosque166"));
  AddExit("noroeste", TBOSQUE("bosque024"));
  ::salidas_cmd();
}
