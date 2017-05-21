#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque214"));
  AddExit("oeste", TBOSQUE("bosque212"));
  AddExit("sur", TBOSQUE("bosque224"));
  AddExit("sudeste", TBOSQUE("bosque225"));
  AddExit("suroeste", TBOSQUE("bosque223"));
  AddExit("norte", TBOSQUE("bosque205"));
  AddExit("nordeste", TBOSQUE("bosque206"));
  AddExit("noroeste", TBOSQUE("bosque204"));
  ::salidas_cmd();
}
