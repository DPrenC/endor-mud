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
  AddExit("oeste", TBOSQUE("bosque191"));
  AddExit("sur", TBOSQUE("bosque198"));
  AddExit("sudeste", TBOSQUE("bosque199"));
  AddExit("suroeste", TBOSQUE("bosque197"));
  AddExit("norte", TBOSQUE("bosque183"));
//  AddExit("nordeste", TBOSQUE("gigantes2"));
  AddExit("noroeste", TBOSQUE("bosque182"));
  ::salidas_cmd();
}
