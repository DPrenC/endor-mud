#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque189"));
  AddExit("oeste", TBOSQUE("bosque187"));
  AddExit("sur", TBOSQUE("bosque194"));
  AddExit("sudeste", TBOSQUE("bosque195"));
  AddExit("suroeste", TBOSQUE("bosque193"));
  AddExit("norte", TBOSQUE("bosque179"));
  AddExit("nordeste", TBOSQUE("bosque180"));
  AddExit("noroeste", TBOSQUE("bosque178"));
  ::salidas_cmd();
}
