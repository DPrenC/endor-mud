#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque040"));
  AddExit("sur", TBOSQUE("bosque055"));
  AddExit("oeste", TBOSQUE("bosque038"));
  AddExit("norte", TBOSQUE("bosque023"));
  AddExit("sudeste", TBOSQUE("bosque056"));
  AddExit("suroeste", TBOSQUE("bosque054"));
  AddExit("nordeste", TBOSQUE("bosque024"));
  AddExit("noroeste", TBOSQUE("bosque022"));
  ::salidas_cmd();
}
