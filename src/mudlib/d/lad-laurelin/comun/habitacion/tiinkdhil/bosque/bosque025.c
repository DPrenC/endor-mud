#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("suroeste");
  SetIntLong(W("Estás en el bosque de lomilmand. La vegetación es muy espesa y deja pocas "
	"posibilidades para seguir. Hacia el noroeste ves una cueva.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque166"));
  AddExit("sur", TBOSQUE("bosque041"));
  AddExit("oeste", TBOSQUE("bosque024"));
  AddExit("sudeste", TBOSQUE("bosque171"));
  AddExit("suroeste", TBOSQUE("bosque040"));
//  AddExit("noroeste", TBOSQUE("trolls2"));
  ::salidas_cmd();
}
