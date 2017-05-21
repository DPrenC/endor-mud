#include "path.h"
inherit TBOSQUE("aleat_bosque");

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("sudeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque003"));
  AddExit("sur", TBOSQUE("bosque006"));
  AddExit("suroeste", TBOSQUE("bosque005"));
  AddExit("nordeste", TBOSQUE("bosque000"));
  ::salidas_cmd();
}
