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
  AddExit("este", TBOSQUE("bosque187"));
  AddExit("oeste", TBOSQUE("bosque185"));
  AddExit("sudeste", TBOSQUE("bosque193"));
  AddExit("norte", TBOSQUE("bosque177"));
  AddExit("nordeste", TBOSQUE("bosque178"));
  AddExit("noroeste", TBOSQUE("bosque176"));
  ::salidas_cmd();
}
