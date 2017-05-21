#include "path.h"
inherit TBOSQUE("aleat_bosque");

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("sur");
  SetPathToGigants("sur");
  SetIntLong(W("Estás en la parte norte del bosque de lomilmand. Al norte"
      " puedes apreciar el final del bosque y el comienzo de la montaña."
      " Puedes elegir ir al nordeste hacia Dular o volver al bosque.\n"));
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("suroeste", TBOSQUE("bosque003"));
  AddExit("sur", TBOSQUE("bosque004"));
  AddExit("oeste", TBOSQUE("bosque000"));
//  AddExit("nordeste", TBOSQUE("dular"));
  ::salidas_cmd();
}
