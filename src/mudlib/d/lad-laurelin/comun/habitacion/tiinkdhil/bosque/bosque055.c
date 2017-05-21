#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque056"));
  AddExit("oeste", TBOSQUE("bosque054"));
  AddExit("sur", TBOSQUE("bosque071"));
  AddExit("sudeste", TBOSQUE("bosque072"));
  AddExit("suroeste", TBOSQUE("bosque070"));
  AddExit("norte", TBOSQUE("bosque039"));
  AddExit("nordeste", TBOSQUE("bosque040"));
  AddExit("noroeste", TBOSQUE("bosque038"));
  ::salidas_cmd();
}
