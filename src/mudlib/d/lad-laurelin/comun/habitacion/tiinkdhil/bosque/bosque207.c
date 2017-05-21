#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque208"));
  AddExit("oeste", TBOSQUE("bosque206"));
  AddExit("sur", TBOSQUE("bosque215"));
  AddExit("sudeste", TBOSQUE("bosque216"));
  AddExit("suroeste", TBOSQUE("bosque214"));
  AddExit("norte", TBOSQUE("bosque199"));
  AddExit("nordeste", TBOSQUE("bosque200"));
  AddExit("noroeste", TBOSQUE("bosque198"));
  ::salidas_cmd();
}
