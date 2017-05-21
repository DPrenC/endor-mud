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
  AddExit("este", TBOSQUE("bosque213"));
  AddExit("oeste", TBOSQUE("bosque211"));
  AddExit("sur", TBOSQUE("bosque223"));
  AddExit("sudeste", TBOSQUE("bosque224"));
  AddExit("suroeste", TBOSQUE("bosque222"));
  AddExit("norte", TBOSQUE("bosque204"));
  AddExit("nordeste", TBOSQUE("bosque205"));
  AddExit("noroeste", TBOSQUE("bosque203"));
  ::salidas_cmd();
}
