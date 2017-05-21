#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque055"));
  AddExit("oeste", TBOSQUE("bosque053"));
  AddExit("sur", TBOSQUE("bosque070"));
  AddExit("sudeste", TBOSQUE("bosque071"));
  AddExit("suroeste", TBOSQUE("bosque069"));
  AddExit("norte", TBOSQUE("bosque038"));
  AddExit("nordeste", TBOSQUE("bosque039"));
  AddExit("noroeste", TBOSQUE("bosque037"));
  ::salidas_cmd();
}
