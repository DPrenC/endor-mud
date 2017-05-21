#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("norte");
  SetPathToGigants("suroeste");
  SetIntLong(W("Estás en el bosque de lomilmand. La vegetación es muy espesa y deja pocas "
	"posibilidades para seguir. Hacia el norte ves una cueva.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque025"));
  AddExit("sur", TBOSQUE("bosque040"));
  AddExit("oeste", TBOSQUE("bosque023"));
  AddExit("sudeste", TBOSQUE("bosque041"));
  AddExit("suroeste", TBOSQUE("bosque039"));
//  AddExit("norte", TBOSQUE("trolls2"));
  ::salidas_cmd();
}
