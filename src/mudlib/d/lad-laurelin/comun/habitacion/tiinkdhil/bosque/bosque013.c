#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque014"));
  AddExit("oeste", TBOSQUE("bosque012"));
  AddExit("sur", TBOSQUE("bosque029"));
  AddExit("sudeste", TBOSQUE("bosque030"));
  AddExit("suroeste", TBOSQUE("bosque028"));
  AddExit("norte", TBOSQUE("bosque008"));
  AddExit("nordeste", TBOSQUE("bosque009"));
  AddExit("noroeste", TBOSQUE("bosque007"));
  ::salidas_cmd();
}
