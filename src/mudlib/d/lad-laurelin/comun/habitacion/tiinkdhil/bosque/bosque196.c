#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque197"));
  AddExit("oeste", TBOSQUE("bosque195"));
  AddExit("sur", TBOSQUE("bosque204"));
  AddExit("sudeste", TBOSQUE("bosque205"));
  AddExit("suroeste", TBOSQUE("bosque203"));
  AddExit("norte", TBOSQUE("bosque190"));
  AddExit("nordeste", TBOSQUE("bosque191"));
  AddExit("noroeste", TBOSQUE("bosque189"));
  ::salidas_cmd();
}
