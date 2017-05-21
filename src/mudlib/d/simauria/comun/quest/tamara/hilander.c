/*
DESCRIPCION  : habitacion de la hilandera, de aqui se coge el velo
FICHERO      : /d/simauria/comun/quest/tamara/hilander.c
MODIFICACION : 18-9-00 [Maler] Creacion.
14/01/2005: [kastwey@simauria]: Arreglo la acci�n de coger el velo
Si pon�as coger qwoepiruqwpeoiruwoepir tambi�n rulaba :D
--------------------------------------------------------------------------------
*/

inherit ROOM;
#include "path.h"
#include <properties.h>
int flag;
public int Query_Flag()
{return flag;}
mixed cmd_mirar(string str)
{
string a,b,Quests;

if(str!="estanterias" && str!="estanter�a" && str!="estanteria" && str!="estanter�as")
return 0;
Quests=TP->QueryQuests();
if (!Quests) Quests="hallo";
if (sscanf(Quests,"%slariton_quest_bruj%s",a,b)!=2)
{
if (flag==1){write("No ves nada en la estanter�a, pero es el sitio perfecto para un\nvelo, quiz� deber�as probar m�s tarde.\n");return 1;}
write("En una de las estanter�as observas un velo negro que parece en buen estado.\n");
tell_room(environment(TP),TP->QueryName()+" mira a las estanter�as.\n",(({TP})));
return 1;
}
write("Las estanter�as est�n vac�as.\n");
tell_room(environment(TP),TP->QueryName()+" mira a las estanter�as.\n",(({TP})));
return 1;
}
cmd_coger(string str)
{
string a,b,Quests;
object ob;
if (str != "velo" && str != "velo de estanteria" && str != "velo de estanter�a" && str != "velo de la estanteria" && str != "velo de la estanter�a") return 0;
Quests=TP->QueryQuests();
if (!Quests) Quests="hallo";
if (sscanf(Quests,"%slariton_quest_bruj%s",a,b)!=2)
{
if (flag==1){write("No encuentras velo para coger!.\n");return 1;}

			tell_object(TP,"Coges un velo negro de una de las estanterias.\n");
	
	         ob=clone_object(QUEST+"/tamara/velo");
ob->move(TP);
flag=1;
             return 1;
}
else {write("No encuentras ning�n velo para coger.\n");return 1;}

			 }

create() {
::create();
 SetIntShort("una choza desvencijada");
  SetIntLong(W("Es una choza en la que antes debi� vivir un artesano. Puedes ver "
  "infinidad de estanter�as, as� como montones de hilos tirados.\n"));
  AddDetail("hilos","Un mont�n de hilo, parece que ya no son utilizables.\n");
  AddExit("noroeste","/d/simauria/comun/habitacion/marhalt/fortaleza/bosque/bosq145");
  flag=0;
}

init()
{
::init();

add_action("cmd_coger","coger");
add_action("cmd_mirar","mirar");
}
reset()
{
::reset();
flag=0;
}