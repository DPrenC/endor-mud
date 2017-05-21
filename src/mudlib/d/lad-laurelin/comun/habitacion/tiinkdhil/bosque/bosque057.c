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
  AddExit("este", TBOSQUE("bosque175"));
  AddExit("oeste", TBOSQUE("bosque056"));
  AddExit("sur", TBOSQUE("bosque073"));
  AddExit("sudeste", TBOSQUE("bosque184"));
  AddExit("suroeste", TBOSQUE("bosque072"));
  AddExit("norte", TBOSQUE("bosque041"));
  AddExit("nordeste", TBOSQUE("bosque171"));
  AddExit("noroeste", TBOSQUE("bosque040"));
  ::salidas_cmd();
}
