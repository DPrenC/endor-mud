#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque215"));
  AddExit("oeste", TBOSQUE("bosque213"));
  AddExit("sur", TBOSQUE("bosque225"));
  AddExit("sudeste", TBOSQUE("bosque226"));
  AddExit("suroeste", TBOSQUE("bosque224"));
  AddExit("norte", TBOSQUE("bosque206"));
  AddExit("nordeste", TBOSQUE("bosque207"));
  AddExit("noroeste", TBOSQUE("bosque205"));
  ::salidas_cmd();
}
