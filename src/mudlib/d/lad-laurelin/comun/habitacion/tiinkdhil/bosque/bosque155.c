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
  AddExit("este", TBOSQUE("bosque156"));
  AddExit("oeste", TBOSQUE("bosque154"));
  AddExit("sudeste", TBOSQUE("bosque159"));
  AddExit("norte", TBOSQUE("bosque150"));
  AddExit("nordeste", TBOSQUE("bosque151"));
  AddExit("noroeste", TBOSQUE("bosque149"));
  ::salidas_cmd();
}
