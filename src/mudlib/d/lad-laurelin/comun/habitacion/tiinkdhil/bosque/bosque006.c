#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("sudeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque007"));
  AddExit("oeste", TBOSQUE("bosque005"));
  AddExit("sur", TBOSQUE("bosque011"));
  AddExit("sudeste", TBOSQUE("bosque012"));
  AddExit("suroeste", TBOSQUE("bosque010"));
  AddExit("norte", TBOSQUE("bosque002"));
  AddExit("nordeste", TBOSQUE("bosque003"));
  ::salidas_cmd();
}
