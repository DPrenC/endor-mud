#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque086"));
  AddExit("oeste", TBOSQUE("bosque084"));
  AddExit("sur", TBOSQUE("camino14"));
  AddExit("sudeste", TBOSQUE("camino15"));
  AddExit("suroeste", TBOSQUE("camino13"));
  AddExit("norte", TBOSQUE("bosque072"));
  AddExit("nordeste", TBOSQUE("bosque073"));
  AddExit("noroeste", TBOSQUE("bosque071"));
  ::salidas_cmd();
}
