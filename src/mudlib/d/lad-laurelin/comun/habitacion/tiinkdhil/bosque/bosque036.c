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
  AddExit("este", TBOSQUE("bosque037"));
  AddExit("sur", TBOSQUE("bosque052"));
  AddExit("oeste", TBOSQUE("bosque035"));
  AddExit("norte", TBOSQUE("bosque020"));
  AddExit("sudeste", TBOSQUE("bosque053"));
  AddExit("suroeste", TBOSQUE("bosque051"));
  AddExit("noroeste", TBOSQUE("bosque019"));
  AddExit("nordeste", TBOSQUE("bosque021"));
  ::salidas_cmd();
}
