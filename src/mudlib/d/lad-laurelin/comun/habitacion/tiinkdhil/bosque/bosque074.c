#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("norte");
  SetIntLong(W("Est�s en los l�mites del bosque de tiinkdhil, la vegetaci�n "
	  "es tan espesa que  casi te cierra el camino. Al norte notas una "
	  "cueva muy grande.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque075"));
  AddExit("sudeste", TBOSQUE("bosque087"));
///:  AddExit("norte", TBOSQUE("gigantes"));
  AddExit("nordeste", TBOSQUE("bosque058"));
  ::salidas_cmd();
}
