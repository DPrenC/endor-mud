#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntLong(W("Estás en el bosque de lomilmand. La vegetación es muy espesa y deja pocas "
	"posibilidades para seguir. Hacia el nordeste ves una cueva.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque024"));
  AddExit("sur", TBOSQUE("bosque039"));
  AddExit("oeste", TBOSQUE("bosque022"));
  AddExit("sudeste", TBOSQUE("bosque040"));
  AddExit("suroeste", TBOSQUE("bosque038"));
//  AddExit("nordeste", TBOSQUE("trolls2"));
  ::salidas_cmd();
}
