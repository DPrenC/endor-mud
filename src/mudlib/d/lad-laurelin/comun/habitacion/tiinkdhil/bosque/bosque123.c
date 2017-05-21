#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque217"));
  AddExit("oeste", TBOSQUE("bosque122"));
  AddExit("sur", TBOSQUE("bosque137"));
  AddExit("sudeste", TBOSQUE("bosque228"));
  AddExit("suroeste", TBOSQUE("bosque136"));
  AddExit("norte", TBOSQUE("bosque109"));
  AddExit("noroeste", TBOSQUE("bosque108"));
  ::salidas_cmd();
}
