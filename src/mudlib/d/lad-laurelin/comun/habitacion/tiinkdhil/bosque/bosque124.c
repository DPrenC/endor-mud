#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque125"));
  AddExit("oeste", TBOSQUE("camino01"));
  AddExit("sur", TBOSQUE("bosque138"));
  AddExit("sudeste", TBOSQUE("bosque139"));
  AddExit("norte", TBOSQUE("camino02"));
  AddExit("nordeste", TBOSQUE("bosque111"));
  AddExit("noroeste", TBOSQUE("bosque110"));
  ::salidas_cmd();
}
