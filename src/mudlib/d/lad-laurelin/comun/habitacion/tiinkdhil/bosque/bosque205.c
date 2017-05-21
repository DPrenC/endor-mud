#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque206"));
  AddExit("oeste", TBOSQUE("bosque204"));
  AddExit("sur", TBOSQUE("bosque213"));
  AddExit("sudeste", TBOSQUE("bosque214"));
  AddExit("suroeste", TBOSQUE("bosque212"));
  AddExit("norte", TBOSQUE("bosque197"));
  AddExit("nordeste", TBOSQUE("bosque198"));
  AddExit("noroeste", TBOSQUE("bosque196"));
  ::salidas_cmd();
}
