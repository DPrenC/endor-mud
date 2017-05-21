/* fuente.c Aqui hay una pequenya fuente. (Einstein el pollo, no te jode)

   ??/06/01 [Maler@Simauria] Creacion

*/


#include <properties.h>
#include <moving.h>
#include "./path.h"

inherit ROOM;

mapping list;

int destransformar()
{
string name, race, quests, a, b;
object bota;
name=TP->QueryName();
quests=TP->QueryQuests();
if(!quests) quests="hallo";
restore_object("/d/kenton/comun/quest/bruja/lista");
race=list[name][0];
TP->SetRace(list[name][0]);
TP->SetFrog(0);
RACEMASTER->InitRace(TP,list[name][0]);
RACEMASTER->AdjustStats(TP);
write(W("Vuelves a ser de raza "+race+", rápidamente coges la bota.\n"));
if(sscanf(quests,"%slariton_quest_bruj%s",a,b)==2)
{tell_object(TP,"Te das cuenta de que ya has ayudado a Turon y tiras la bota al río.\n"); return 1;}
bota=clone_object("/d/kenton/comun/quest/bruja/bota");
if(bota->move(TP,M_SILENT)!=ME_OK)
   {
    tell_object(TP,"No puedes con la bota, asi que la dejas en el suelo.\n");
    bota->move(environment(TP),M_SILENT);
   }
list[name]=([]);
save_object("/d/kenton/comun/quest/bruja/lista");
return 1;
}

haz_beber(str)
{
 if (!str)
 {
 write ("Beber que?\n");
 return 1;
 }
 else
  if(str!="agua"&&str!="agua de fuente"&&str!="de fuente")
  {
   write("No encuentras "+str+" para beber.\n");
   return 1;
  }
  else
 {
  if (TP->QueryDrink()>=TP->QueryMaxDrink())
   {
    write("Bebes un poquito de agua.\n");
    say (capitalize(TP->QueryName())+" intenta beber en la fuente, pero ya está lleno.\n");
    if(TP->QueryRace()=="rana_bota_quest") destransformar();
    else write(W("Te sientes más "+TP->QueryRace()+" que nunca.\n"));
    return 1;
   }
  TP->SetDrink(TP->QueryDrink()+5);
 }
 say(capitalize(TP->QueryName())+" bebe agua de la fuente. Parece refrescante...\n");
 write("Bebes un buen trago de agua de la fuente. "
       "Sabe como a grafito, además esta muy caliente...\n");
 if(TP->QueryRace()=="rana_bota_quest") destransformar();
 else {write(W("Te sientes más "+TP->QueryRace()+" que nunca.\n"));}
 return 1;
}


init() {
add_action("haz_beber","beber");
::init();
}



create () {
  ::create();

  Set(P_INT_SHORT,"la fuente de la Sensación");
  Set(P_INT_LONG,W(
 "Ésta es la fuente de la Sensación, famosa en el mundo entero, cuentan que "
 "en cierta ocasión, un malvado mago se hizo pasar por el alcalde del pueblo, "
 "y q al beber de la fuente, mostro su verdadera forma a los kenders, que le "
 "invitaron amablemente a salir del pueblo, esa guerra de tartas pasó a la "
 "historia del pequeño poblado de Klariton.\n"));
  SetLocate("Klariton");
  SetIndoors(0);
AddDetail(({"encina","arbol","árbol"}),
"Es enorme. Sus ramas deben dar buena sombra.\n");
 AddDetail(({"pozo"}),
"Es un pozo como otro cualquiera.\n");
AddDetail(({"fuente"}),
"Es una pequeña fuente. Quizá puedas beber agua de ella.\n");
AddDetail(({"casa"}),
"Es una casa cerrada. No podrás entrar en ella.\n");
AddDetail(({"guijarros"}),
"Pequeños guijarros redondeados. Es mejor que la tierra malamente apisonada que"
"hay en el resto de la calle.\n");
AddExit("sur","./calle41s");

}