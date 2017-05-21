#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque071"));
  AddExit("oeste", TBOSQUE("bosque069"));
  AddExit("sur", TBOSQUE("bosque083"));
  AddExit("sudeste", TBOSQUE("bosque084"));
  AddExit("suroeste", TBOSQUE("bosque082"));
  AddExit("norte", TBOSQUE("bosque054"));
  AddExit("nordeste", TBOSQUE("bosque055"));
  AddExit("noroeste", TBOSQUE("bosque053"));
  ::salidas_cmd();
}
