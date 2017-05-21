/***************************************************************************************
 ARCHIVO:	pajar.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	El pajar lugar de encuentro de enamorados y demás XD
 MODIFICACION:  09-04-2003 Añado los hilillos para el quest de Draego.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

public int QueryEntrarPatrullero()	{return 1;}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("el pajar");
  SetIntSmell("Hueles a paja seca.\n");
  SetIntNoise("Cada vez que algo se mueve, la paja cruje sin cesar.\n");
  SetIntLong(W("Estás en el pajar. No es más que una caseta de madera llena de paja "
  	"de diferentes tipos que la almacenan aquí tras la siega para dar de comer a los "
  	"animales. Este sería un romántico lugar para esconderse.\n"));
  AddDetail(({"paja","suelo","pared","paredes"}),"Todo está cubierto de paja.\n");
  AddDetail(({"techo"}),"Es un techo de madera no muy alto. Parece en buen estado.\n");
  carcel=(RHOEHAB("koek/calles/folker_00"));
  AddExit("norte",RHOEHAB("koek/calles/folker_00"));
  AddItem(RHOEPNJ("koek/granja/adwel"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/granja/geagan"),REFRESH_DESTRUCT,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("coger","fcoger");
}

public int fcoger(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");
	
	if(str) lower_case(str);
	if (quest && member(quest,"tunica") && quest["tunica",0]==8 && str && str=="paja")
	{
		quest+=(["tunica":9]);
		clone_object(RHOEVAR("koek/granja/hilos"))->move(TP,M_SILENT);
		write("Coges unos finísimos y alargados hilos de paja.\n");
		return 1;
	}
	else if (str && str=="paja")
	{
		write("Está demasiado compacta para coger un poco, así que no coges nada.\n");
		return 1;
	}
return 0;
}
