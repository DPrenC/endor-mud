#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque195"));
  AddExit("oeste", TBOSQUE("bosque193"));
  AddExit("sur", TBOSQUE("bosque202"));
  AddExit("sudeste", TBOSQUE("bosque203"));
  AddExit("suroeste", TBOSQUE("bosque201"));
  AddExit("norte", TBOSQUE("bosque188"));
  AddExit("nordeste", TBOSQUE("bosque189"));
  AddExit("noroeste", TBOSQUE("bosque187"));
  ::salidas_cmd();
}
