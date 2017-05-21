/*
   ##################################################################
   ## jard_room.c : Habitacion estandard para los Jardines Reales  ##
   ## Creacion : 17/10/97. [n] Nemesis (nemesis@simauria.upv.es)   ##
   ## Nota: Oler las flores tendra diversos efectos. Tendremos     ##
   ##      diversas flores definidas (SetFlower) y cada habitacion ##
   ##      tendra una flor definida.                               ##
   ##								   ##
   ## Modificaciones: 						   ##
   ##  [n] 21-Abr-2001 Eliminada SetPlus, ya que por fin averigüé  ##
   ##		      cómo demonios hacer una IntLong que cambiase,##
   ##                 pero que retuviese una parte común.          ##
   ##                 De hecho, haz_long ha cambiado de nombre,    ##
   ##                 ya que sólo permite mirar las flores que hay ##
   ##                 en cada habitación (m_flor)                  ##
   ##                 Introducido el uso del skill "buscar" y      ##
   ##                 dividida "haz_buscar" en "haz_buscar" y      ##
   ##                 "haz_encontrar"                              ##
   ##################################################################
*/

#include <moving.h>
#include <properties.h>
#include "../path.h"


inherit SIM_ROOM;

public int num;

public int SetFlower(string str) {

 Set("flower",str);
 return 1;

}

haz_oler(str) {
string flor;
flor=TO->Query("flower");
 if ((!str)) {
  return 0;
 }
 if (str=="flores") {
 write("Huele a "+TO->Query("flower")+"s.\n");
 write(flor);
 return 1;
 }
 if (str==flor+"s") {
  write ("Huelen muy bien.\n");
 return 1;
 }
 return 0;
}

string ver_flores() {
return "Hay todo tipo de flores. En este lugar hay sobre todo "+Query("flower")+"s. "
 "De repente piensas que éste es el lugar ideal para que la gente pierda cosas. "
 "Quizá sería fructifera una búsqueda entre las flores...\n";
}

string QueryIntLong()
{
string desc;
desc = "Estás dentro de los Jardines Reales. Los aromas de miles de flores multicolor "
"se mezclan con la algarabía de cientos de aves y el zumbido de los insectos que "
"los pueblan en una extraña armonía de colores, olores y sonidos.\n"+
 ::QueryIntLong();
 return desc;
}



m_flor(str) {
object room;
string desc;

room=TO;

if ((str==(room->Query("flower"))+"s")||(str==room->Query("flower")))
 {
 write("Son la flor predominante aquí. Lo llenan todo con sus bellos colores.\n");
 return 1;
 }
}

haz_buscar(str) {
int x,trial;

 if (!str) return 0;
 if (str!="entre flores"&&str!="entre las flores")
 {
 write("Sólo puedes buscar entre las flores.\n");
 return 1;
 }
 if (num==0) {
 write("De alguna manera, sabes que no vas a encontrar nada aquí...\n");
 say(TP->QueryName()+" busca entre las flores.\n");
 return 1;
 }
 trial = TP->UseSkill("rastrear");
 say(TP->QueryName()+" busca entre las flores.\n");
 if (trial > num) {
  x=random(20);
  haz_encontrar(x);
  return 1;
 }
 else {
   write("No has encontrado nada.\n");
   return 1;
  }
}

int haz_encontrar(int x) {
object ob;

 switch(x) {
  case 0: {
           num=num-1;
           write("Has encontrado un arma.\n");
	   ob=clone_object(ARMA("arma"));
	   ob->move(TP,M_SILENT);
	   break;
          }
  case 1: {
           num=num-1;
           write("Has encontrado una armadura.\n");
	   ob=clone_object(PROT("armadura"));
 	   ob->move(TP,M_SILENT);
	   break;
          }
  case 2: {
           write("Has encontrado una flor.\n");
    	   ob=clone_object(OTRO("flor"));
	   ob->move(TP,M_SILENT);
	   break;
          }
  case 3: {
           write("¡Has encontrado un bicho! ¡Puaj, qué asco!\n");
	   ob=clone_object("std/npc");
	   ob->SetName("un bicho");
	   ob->SetShort("un bicho");
	   ob->SetLong("Un bicho que vive entre las flores.\n");
	   ob->SetHands(({({"la pata delantera derecha",0,1}),
		          ({"la pata delantera izquierda",0,1})}));
	   ob->SetHP(1+random(10));
	   ob->SetMaxHP(10);
	   ob->SetLevel(1);
	   ob->SetAlignment(0);
	   ob->SetGender(GENDER_NEUTER);
	   ob->SetWeight(15);
	   ob->AddId(({"bicho"}));
	   ob->move(TP,M_SILENT);
	   break;
          }
  case 4: {
           num=num-1;
           write("Has encontrado un objeto muy raro.\n");
	   ob=clone_object(OTRO("raro"));
	   ob->move(TP,M_SILENT);
	   break;
          }
  default: write("No has encontrado nada.\n");

 }
 return 1;
}



init() {
 add_action("haz_oler","oler");
 add_action("haz_buscar","buscar");
 add_action("m_flor","mirar");
 add_action("m_flor","m");
 ::init();
}


create()
{
 ::create();
 num=random(10);
 SetLocate("Simauria Capital");
 SetIntShort("los Jardines Reales");
 SetIntLong(
"Estas dentro de los Jardines Reales. Los aromas de miles de flores multicolor "
"se mezclan con la algarabía de cientos de aves y el zumbido de los insectos que "
"los pueblan en una extraña armonía de colores, olores y sonidos.\n");
 SetIndoors(0);
 SetIntNoise(
 "Oyes los cantos de los cientos de aves que pueblan los jardines.\n");
 SetIntSmell("Los dulces aromas de las flores llenan el aire.\n");
 SetServer(SERVER);
 SetFlower("rosa");
 AddDetail("flores",SF(ver_flores));
 AddDetail(({"jardines","Jardines","Jardines Reales"}),
"Estas enmedio de ellos. Un dulce aroma a flores llena el aire.\n");
 AddDetail(({"aves","pajaros"}),
 "No ves ningun pajaro, pero puedes oirlos.\n");
 AddDetail(({"sendero"}),
"Estas en un estrecho sendero que recorre los Jardines Reales.\n");
}
