#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("norte");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque202"));
  AddExit("oeste", TCSUELO("salida3"));
  AddExit("sur", TBOSQUE("bosque209"));
  AddExit("sudeste", TBOSQUE("bosque210"));
  AddExit("norte", TBOSQUE("bosque193"));
  AddExit("nordeste", TBOSQUE("bosque194"));
  ::salidas_cmd();
}
