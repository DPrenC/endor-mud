#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque108"));
  AddExit("oeste", TBOSQUE("bosque106"));
  AddExit("sur", TBOSQUE("bosque121"));
  AddExit("sudeste", TBOSQUE("bosque122"));
  AddExit("suroeste", TBOSQUE("bosque120"));
  AddExit("norte", TBOSQUE("camino13"));
  AddExit("nordeste", TBOSQUE("camino14"));
  AddExit("noroeste", TBOSQUE("camino12"));
  ::salidas_cmd();

}
