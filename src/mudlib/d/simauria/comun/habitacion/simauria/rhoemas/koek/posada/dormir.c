/***************************************************************************************
 ARCHIVO:	dormir.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Los dormitorios de la posada
 			Cambio parte para que sea de 1 solo uso por vale. Además ahora solo
 			regenera 10 de magia cada vez (por eso de que hay mucha pasta por sim)
 			Vale... cambio que no me acordaba que los vales eran carillos. Recuperas
 			todo, como antes.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <magia.h>

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("el dormitorio");
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Aquí en los dormitorios los peregrinos descansar durmiendo en las camas "
  	"para poder estar como nuevos en su visita al templo. Hay varias camas de madera "
  	"muy cómodas en las que puedes dormir, pues quedan muchas sin ocupar. Se respira "
  	"una paz absoluta.\n"));
  AddDetail(({"cama","camas"}),W("Todas las camas de esta habitación parecen igual de "
  	"cómodas. Hay algunas libres, así que puedes dormir.\n"));
  AddDetail(({"paredes","pared","techo","suelo"}),"Es de madera y muy normal.\n");
  carcel=(RHOEHAB("koek/posada/entrada"));
  ForbidAllMagic("Aquí se recupera, no se gasta. No puedes hacer magia.\n");
  Set(P_TPORT,TPORT_NO);
  AddExit("sudeste",RHOEHAB("koek/posada/entrada"));
  AddItem(RHOEPNJ("koek/posada/peregrino_dormir"),1,2+random(4));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("dormir","fdormir");
}

int fnada(string str)
{
	write("Zzzzzzzzzzzz. Sueñas con las maravillosas aventuras que te esperan.\n");
	say(W(CATP+" está dormido. Parece que sueña.\n"),TP);
	return 1;
}

int ffin()
{
	remove_action("",TP);
	write("Te despiertas con mucha mejor cara y sales a la entrada de la posada...\n");
	say(W(CATP+" se despierta tras el largo sueño y sale del dormitorio con mejor cara."),TP);
	TP->move(carcel,M_GO);
	return 1;
}

int faccion(int time)
{
	add_action("fnada","",1);
	call_out("ffin",time);
	TP->SetSP(TP->QueryMaxSP());
	return 1;
}

int fdormir(string str)
{
	if (TP->Fighting()){
	   write ("Cuando te vas a dormir, te das cuenta de que estás en mitad de una "
	          "lucha y decides esperar.\n");
	   return 1;
	}
	write("Te tumbas en una de las camas, y es tan cómoda que enseguida te "
		"duermes..\n");
	say(CATP+" se tumba en una de las camas y se pone a dormir.\n",TP);
	faccion(25);
	return 1;
}
