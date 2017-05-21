#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque053"));
  AddExit("oeste", TBOSQUE("bosque051"));
  AddExit("sur", TBOSQUE("bosque068"));
  AddExit("sudeste", TBOSQUE("bosque069"));
  AddExit("suroeste", TBOSQUE("bosque067"));
  AddExit("norte", TBOSQUE("bosque036"));
  AddExit("nordeste", TBOSQUE("bosque037"));
  AddExit("noroeste", TBOSQUE("bosque035"));
  ::salidas_cmd();
}
