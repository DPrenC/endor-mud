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
  AddExit("este", TBOSQUE("bosque067"));
  AddExit("oeste", TBOSQUE("bosque065"));
  AddExit("sur", TBOSQUE("camino08"));
  AddExit("sudeste", TBOSQUE("camino09"));
  AddExit("suroeste", TBOSQUE("camino07"));
  AddExit("norte", TBOSQUE("bosque050"));
  AddExit("nordeste", TBOSQUE("bosque051"));
  AddExit("noroeste", TBOSQUE("bosque049"));
  ::salidas_cmd();
}
