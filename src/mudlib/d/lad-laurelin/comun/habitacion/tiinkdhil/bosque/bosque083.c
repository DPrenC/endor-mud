#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque084"));
  AddExit("oeste", TBOSQUE("bosque082"));
  AddExit("sur", TBOSQUE("camino12"));
  AddExit("sudeste", TBOSQUE("camino13"));
  AddExit("suroeste", TBOSQUE("camino11"));
  AddExit("norte", TBOSQUE("bosque070"));
  AddExit("nordeste", TBOSQUE("bosque071"));
  AddExit("noroeste", TBOSQUE("bosque069"));
  ::salidas_cmd();
}
