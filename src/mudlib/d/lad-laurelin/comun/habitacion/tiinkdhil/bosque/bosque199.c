#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque200"));
  AddExit("oeste", TBOSQUE("bosque198"));
  AddExit("sur", TBOSQUE("bosque207"));
  AddExit("sudeste", TBOSQUE("bosque208"));
  AddExit("suroeste", TBOSQUE("bosque206"));
  AddExit("noroeste", TBOSQUE("bosque192"));
  ::salidas_cmd();
}
