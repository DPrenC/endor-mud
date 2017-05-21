#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque186"));
  AddExit("oeste", TBOSQUE("bosque184"));
  AddExit("sur", TCSUELO("salida1")); //entrada a tiink
  AddExit("norte", TBOSQUE("bosque176"));
  AddExit("nordeste", TBOSQUE("bosque177"));
  AddExit("noroeste", TBOSQUE("bosque175"));
  ::salidas_cmd();
}
