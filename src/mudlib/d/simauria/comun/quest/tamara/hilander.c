/*
DESCRIPCION  : habitacion de la hilandera, de aqui se coge el velo
FICHERO      : /d/simauria/comun/quest/tamara/hilander.c
MODIFICACION : 18-9-00 [Maler] Creacion.
14/01/2005: [kastwey@simauria]: Arreglo la acción de coger el velo
Si ponías coger qwoepiruqwpeoiruwoepir también rulaba :D
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

if(str!="estanterias" && str!="estantería" && str!="estanteria" && str!="estanterías")
return 0;
Quests=TP->QueryQuests();
if (!Quests) Quests="hallo";
if (sscanf(Quests,"%slariton_quest_bruj%s",a,b)!=2)
{
if (flag==1){write("No ves nada en la estantería, pero es el sitio perfecto para un\nvelo, quizá deberías probar más tarde.\n");return 1;}
write("En una de las estanterías observas un velo negro que parece en buen estado.\n");
tell_room(environment(TP),TP->QueryName()+" mira a las estanterías.\n",(({TP})));
return 1;
}
write("Las estanterías están vacías.\n");
tell_room(environment(TP),TP->QueryName()+" mira a las estanterías.\n",(({TP})));
return 1;
}
cmd_coger(string str)
{
string a,b,Quests;
object ob;
if (str != "velo" && str != "velo de estanteria" && str != "velo de estantería" && str != "velo de la estanteria" && str != "velo de la estantería") return 0;
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
else {write("No encuentras ningún velo para coger.\n");return 1;}

			 }

create() {
::create();
 SetIntShort("una choza desvencijada");
  SetIntLong(W("Es una choza en la que antes debió vivir un artesano. Puedes ver "
  "infinidad de estanterías, así como montones de hilos tirados.\n"));
  AddDetail("hilos","Un montón de hilo, parece que ya no son utilizables.\n");
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