#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque085"));
  AddExit("oeste", TBOSQUE("bosque083"));
  AddExit("sur", TBOSQUE("camino13"));
  AddExit("sudeste", TBOSQUE("camino14"));
  AddExit("suroeste", TBOSQUE("camino12"));
  AddExit("norte", TBOSQUE("bosque071"));
  AddExit("nordeste", TBOSQUE("bosque072"));
  AddExit("noroeste", TBOSQUE("bosque070"));
  ::salidas_cmd();
}
