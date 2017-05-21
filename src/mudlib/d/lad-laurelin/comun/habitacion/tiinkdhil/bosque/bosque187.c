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
  AddExit("este", TBOSQUE("bosque188"));
  AddExit("oeste", TBOSQUE("bosque186"));
  AddExit("sur", TBOSQUE("bosque193"));
  AddExit("sudeste", TBOSQUE("bosque194"));
  AddExit("norte", TBOSQUE("bosque178"));
  AddExit("nordeste", TBOSQUE("bosque179"));
  AddExit("noroeste", TBOSQUE("bosque177"));
  ::salidas_cmd();
}
