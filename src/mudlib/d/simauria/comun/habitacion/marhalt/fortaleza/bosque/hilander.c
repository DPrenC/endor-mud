/*
DESCRIPCION  : habitacion de la hilandera, de aqui se coge el velo
FICHERO      : /d/simauria/comun/quest/tamara/hilander.c
MODIFICACION : 18-9-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit SIM_ROOM;
#include <properties.h>

cmd_coger(string str)
{
object ob;
			tell_object(TP,"Coges un velo negro de una de las estanterias.\n");
	
	         ob=clone_object(QUEST+"/tamara/velo");
ob->move(TP);
             return 1;
			 }

create() {
::create();
 SetIntShort("una choza desvencijada");
  SetIntLong(W("Es una choza en la que antes debi� vivir un artesano. Puedes ver "
  "infinidad de estanter�as, as� como montones de hilos tirados.\n"));
  AddDetail("hilos","Un mont�n de hilo, parece que ya no son utilizables.\n");
AddDetail(({"estanterias","estanter�a","estanteria","estanter�as"}),"En una de las estanter�as observas un velo negro que parece en buen estado.\n");
  AddExit("noroeste","/d/simauria/comun/habitacion/marhalt/fortaleza/bosque/bosq145");

}

init()
{
::init();

add_action("cmd_coger","coger");

}
