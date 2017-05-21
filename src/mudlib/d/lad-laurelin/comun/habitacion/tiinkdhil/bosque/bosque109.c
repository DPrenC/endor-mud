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
  AddExit("oeste", TBOSQUE("bosque108"));
  AddExit("sur", TBOSQUE("bosque123"));
  AddExit("sudeste", TBOSQUE("bosque217"));
  AddExit("suroeste", TBOSQUE("bosque122"));
  AddExit("norte", TBOSQUE("camino15"));
  AddExit("noroeste", TBOSQUE("camino14"));
  ::salidas_cmd();

}
