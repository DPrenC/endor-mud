#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque220"));
  AddExit("oeste", TBOSQUE("bosque218"));
  AddExit("sur", TBOSQUE("bosque230"));
  AddExit("sudeste", TBOSQUE("bosque231"));
  AddExit("suroeste", TBOSQUE("bosque229"));
  AddExit("nordeste", TBOSQUE("bosque209"));
  ::salidas_cmd();
}
