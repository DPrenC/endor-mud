#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque207"));
  AddExit("oeste", TBOSQUE("bosque205"));
  AddExit("sur", TBOSQUE("bosque214"));
  AddExit("sudeste", TBOSQUE("bosque215"));
  AddExit("suroeste", TBOSQUE("bosque213"));
  AddExit("norte", TBOSQUE("bosque198"));
  AddExit("nordeste", TBOSQUE("bosque199"));
  AddExit("noroeste", TBOSQUE("bosque197"));
  ::salidas_cmd();
}
