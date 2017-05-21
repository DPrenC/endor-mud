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
  AddExit("este", TBOSQUE("bosque205"));
  AddExit("oeste", TBOSQUE("bosque203"));
  AddExit("sur", TBOSQUE("bosque212"));
  AddExit("sudeste", TBOSQUE("bosque213"));
  AddExit("suroeste", TBOSQUE("bosque211"));
  AddExit("norte", TBOSQUE("bosque196"));
  AddExit("nordeste", TBOSQUE("bosque197"));
  AddExit("noroeste", TBOSQUE("bosque195"));
  ::salidas_cmd();
}
