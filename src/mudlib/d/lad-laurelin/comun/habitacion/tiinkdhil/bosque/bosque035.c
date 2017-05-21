#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("norte");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque036"));
  AddExit("sur", TBOSQUE("bosque051"));
  AddExit("oeste", TBOSQUE("bosque034"));
  AddExit("norte", TBOSQUE("bosque019"));
  AddExit("sudeste", TBOSQUE("bosque052"));
  AddExit("suroeste", TBOSQUE("bosque050"));
  AddExit("noroeste", TBOSQUE("bosque018"));
  AddExit("nordeste", TBOSQUE("bosque020"));
  ::salidas_cmd();
}
