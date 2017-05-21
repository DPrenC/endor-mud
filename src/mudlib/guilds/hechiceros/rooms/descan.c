#include "path.h"
inherit ROOM;

create(){
  ::create();
  SetLocate("Gremio de Hechiceros");
  SetIndoors(1);
  SetIntBright(50);	
  SetIntLong(W("estas en una habitacion en la que puedes descansar de tus viajes"
" la habitacion esta decorada con unos dibujos que parecen cambiar de aspecto dependiendo"
" del angulo desde donde los mires a parte de eso ves unos sofas para descansar.\n"));
AddDetail(({"sofa","sofas"}),"Hay bastantes sofas esparcidos por toda la sala parecn comodos.\n");
AddDetail(({"dibujo","dibujos"}),"Los dibujos son cambiantes y representan la historia del gremio.\n");
AddRoomCmd("sentarse","cmd_sentarse");
  AddExit("este", "./esca1");
}
int cmd_sentarse(string str)
     {if (!str || str!="en sofa")
         return notify_fail("te sientas en el suelo\n"),0;

       write("te sientas en los sofas y notas como tu cuerpo te lo agradece inmediatamente.\n");
       return 1;
     }