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
  AddExit("este", TBOSQUE("bosque198"));
  AddExit("oeste", TBOSQUE("bosque196"));
  AddExit("sur", TBOSQUE("bosque205"));
  AddExit("sudeste", TBOSQUE("bosque206"));
  AddExit("suroeste", TBOSQUE("bosque204"));
  AddExit("norte", TBOSQUE("bosque191"));
  AddExit("nordeste", TBOSQUE("bosque192"));
  AddExit("noroeste", TBOSQUE("bosque190"));
  ::salidas_cmd();
}
