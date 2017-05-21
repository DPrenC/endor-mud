#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino02"));
  AddExit("sur", TBOSQUE("camino01"));
  AddExit("sudeste", TBOSQUE("bosque124"));
  AddExit("norte", TBOSQUE("bosque096"));
  AddExit("nordeste", TBOSQUE("bosque097"));
  AddExit("noroeste", TBOSQUE("bosque095"));
  // se esconden las salidas para confundir al jugador y hacerlo rastrear
  ::salidas_cmd();
}
