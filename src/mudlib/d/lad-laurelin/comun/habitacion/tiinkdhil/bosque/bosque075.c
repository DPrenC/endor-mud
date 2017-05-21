#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntLong(W("Estás en los límites del bosque de tiinkdhil, la vegetación "
	  "es tan espesa que  casi te cierra el camino. Al noroeste notas una "
	  "cueva muy grande.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque076"));
  AddExit("oeste", TBOSQUE("bosque074"));
  AddExit("sur", TBOSQUE("bosque087"));
  AddExit("sudeste", TBOSQUE("bosque088"));
  AddExit("norte", TBOSQUE("bosque058"));
  AddExit("nordeste", TBOSQUE("bosque059"));
//   AddExit("noroeste", TBOSQUE("gigantes"));
  ::salidas_cmd();
}
