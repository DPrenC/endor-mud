#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("oeste");
  SetIntLong(W("Estás en los límites del bosque de tiinkdhil, la vegetación "
	"es tan espesa que casi te cierra el camino. Al oeste notas una cueva "
	  "muy grande.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque059"));
//  AddExit("oeste", TBOSQUE("gigantes"));
  AddExit("sur", TBOSQUE("bosque075"));
  AddExit("sudeste", TBOSQUE("bosque076"));
  AddExit("suroeste", TBOSQUE("bosque074"));
  AddExit("norte", TBOSQUE("bosque042"));
  AddExit("nordeste", TBOSQUE("bosque043"));
  ::salidas_cmd();
}
