#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("norte");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque073"));
  AddExit("oeste", TBOSQUE("bosque071"));
  AddExit("sur", TBOSQUE("bosque085"));
  AddExit("sudeste", TBOSQUE("bosque086"));
  AddExit("suroeste", TBOSQUE("bosque084"));
  AddExit("norte", TBOSQUE("bosque056"));
  AddExit("nordeste", TBOSQUE("bosque057"));
  AddExit("noroeste", TBOSQUE("bosque055"));
  ::salidas_cmd();
}
