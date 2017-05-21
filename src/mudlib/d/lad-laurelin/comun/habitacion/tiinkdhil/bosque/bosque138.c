#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque139"));
  AddExit("norte", TBOSQUE("bosque124"));
  AddExit("nordeste", TBOSQUE("bosque125"));
  AddExit("noroeste", TBOSQUE("camino01"));
  ::salidas_cmd();
}
