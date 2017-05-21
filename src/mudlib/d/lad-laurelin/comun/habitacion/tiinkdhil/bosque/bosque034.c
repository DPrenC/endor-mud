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
  AddExit("este", TBOSQUE("bosque035"));
  AddExit("sur", TBOSQUE("bosque050"));
  AddExit("oeste", TBOSQUE("bosque033"));
  AddExit("norte", TBOSQUE("bosque018"));
  AddExit("sudeste", TBOSQUE("bosque051"));
  AddExit("suroeste", TBOSQUE("bosque049"));
  AddExit("noroeste", TBOSQUE("bosque017"));
  AddExit("nordeste", TBOSQUE("bosque019"));
  ::salidas_cmd();
}
