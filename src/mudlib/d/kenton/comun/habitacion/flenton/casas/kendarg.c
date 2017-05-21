/***************************************************************************************
 ARCHIVO:	kendarg.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	La casa de kendarg, el héroe local
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

object kendarg;
string *a_cosas,*a_ruta;
int *a_estado;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas una dulce melodía.\n");
  SetIntSmell("Huele a frutas del bosque.\n");

  SetIntShort("la casa de Kendarg");
  SetIntLong("Estás en la casa de Kendarg, el héroe local. En una casa "
  	"grande para ser de un kender, y está bien amueblada. Las paredes "
  	"parecen brillar con el reflejo del gran número de objetos que las "
  	"cubren. Hay armas y armaduras, tapices, y repisas, con varias piedras "
  	"verdes, entre otras cosas, y una cuchara de palo. Al fondo hay un "
  	"sillón, colocado frente a una chimenea y en el centro de la habitación "
  	"hay una mesa alargada, y sillas a su alrededor.\n");

  AddDetail(({"pared"}),"Las paredes están repletas de los objetos más "
  	"diversos, y brillantes, hay armas, armaduras, piedras verdes... y "
  	"una cuchara de palo.\n");
  AddDetail(({"cuchara","cuchara de palo"}),"Es una simple cuchara de palo.\n");
  AddDetail(({"piedras","piedras verdes","piedra"}),"Hay varias piedras verdes "
	"colocadas en una repisa.\n");
  AddDetail(({"silla"}),"Es una silla pequeña de madera tapizada de rojo.\n");
  AddDetail(({"armas"}),"Hay armas muy diversas, desde una daga, hasta un hacha "
  	"de guerra. Todas parecen sin usar.\n");
  AddDetail(({"daga"}),"Es una daga con una empuñadura bastante adornada.\n");
  AddDetail(({"hacha"}),"Es un hacha de guerra nueva.\n");
  AddDetail(({"escudo"}),"Es un escudo de metal, esta algo abollado.\n");
  AddDetail(({"sillon"}),"Es un gran sillón de color rojo. Parece muy confortable.\n");
  AddDetail(({"tapiz"}),"Es un tapiz muy bonito. Representa un dragón verde.\n");
  AddDetail(({"chimenea"}),"Es una chimenea de ladrillos rojos. Está encendida.\n");
  AddDetail(({"mesa"}),"Es una mesa alargada. Encima hay velas, y varios platos y vasos.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera.\n");
  AddDetail(({"vela"}),"Es una vela blanca. Está algo consumida.\n");

  AddRoomCmd("coger","fcoger");

  AddExit("este",FLENHAB+"calles/plaza_01");

  a_cosas=({"cuchara","piedra","silla","daga","hacha","escudo","sillon","tapiz","mesa","plato","vaso","vela"});
  a_estado=({1,1,-1,1,1,1,-1,1,-1,1,1,1});
  a_ruta=({FLENVAR+"cuchara",FLENVAR+"piedra_verde","",FLENARM+"daga",
  	   FLENARM+"hacha",FLENPRT+"escudo","",FLENVAR+"tapiz","",
  	   FLENVAR+"plato",FLENVAR+"vaso",FLENVAR+"vela"});
}

init(){
  ::init();

  if (!kendarg)
  {
	kendarg=clone_object(FLENPNJ+"poblado/kendarg");
	kendarg->move(TO,M_SILENT);
  }
}

fclona(string cosa, string *conj_cosas, int *flag, string *ruta)
{
	int i;
	object objeto;
	i=member(conj_cosas, cosa);
	if (i==-1)
	{
		notify_fail("¿Coger <qué>?\n");
		return 0;
	}
	else
	{
		if(flag[i]<1)
		{
			if(flag[i]==-1)
				write("No creo que al dueño de la casa le guste que "
				"le cogas un/una "+conj_cosas[i]+".\n");
			else
				write("No encuentras "+conj_cosas[i]+" para coger.\n");
				return 1;
  		}
  		else
  		{
  			flag[i]=0;
			if (!objeto)
			{
				objeto=clone_object(ruta[i]);
				objeto->move(TP);
				write("Coges "+objeto->QueryShort()+".\n");
				say(CATP+" coge "+objeto->QueryShort()+".\n");
			}
		}
	}
	return 1;
}

int fcoger(string str)
{
	   if (fclona(str,a_cosas, a_estado, a_ruta)) return 1;
    return 0;
}
