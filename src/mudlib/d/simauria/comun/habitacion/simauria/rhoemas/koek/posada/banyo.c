/***************************************************************************************
 ARCHIVO:		banyo.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Los ba�os de la posada
 			Cambio parte para que sea de 1 solo uso por vale. Adem�s ahora solo
 			regenera 10 de salud cada vez (por eso de que hay mucha pasta por sim)
 			Vale... cambio que no me acordaba que los vales eran carillos. Recuperas
 			todo, como antes.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("el ba�o");
  SetIntSmell("Aspiras una gran cantidad de vapor de agua.\n");
  SetIntNoise("Oyes el burbujeo del agua en las balsas.\n");
  SetIntLong(W("Estos son los ba�os de la posada. Aqu� puedes ba�arte en una de las "
  	"balsas que hay y relajarte un poco del duro camino que llevas recorrido. "
  	"Suele haber peregrinos ase�ndose antes de visitar el templo. No ves muy bien "
  	"porque hay una densa capa de vapor de agua flotando por la habitaci�n.\n"));
  AddDetail(({"vapor","agua","aire"}),W("El agua de las balsas calientes se evapora formando "
  	"una gruesa capa de vapor de agua en el aire que no te deja ver casi nada.\n"));
  AddDetail(({"balsa","balsas","balsa caliente","balsas calientes"}),W("Hay unas cuantas "
  	"balsas llenas de agua caliente en las que te puedes ba�ar.\n"));
  AddDetail(({"paredes","pared","techo","suelo"}),W("No puedes ver eso con claridad, el "
  	"vapor de agua te lo impide.\n"));
  carcel=(RHOEHAB("koek/posada/entrada"));
  AddExit("suroeste",RHOEHAB("koek/posada/entrada"));
  AddItem(RHOEPNJ("koek/posada/peregrino_banyo"),1,2+random(4));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("banyarse","fbanyarse");
  AddRoomCmd("ba�arse","fbanyarse");
  AddRoomCmd("beber","fbeber");
}

int fbeber(string str)
{
	if (str=="agua")
	{
		write("Es agua para ba�arse, no para beber.\n");
		return 1;
	}
}

int fbanyarse(string str)
{
	if (TP->Fighting()){
	   write (W("Cuando te vas a ba�ar, te das cuenta de que est�s en mitad de una lucha y decides esperar.\n"));
	   return 1;
	}
	write(W("Te ba�as un rato en una de las balsas. El agua caliente te relaja "
		"los m�sculos y te ayuda a recuperarte.\nAl poco rato sales con mejor aspecto."));
	say(W(CATP+" se ba�a en una de las balsas de agua caliente. Parece relajado "
		"y muy descansado. Al poco rato sale con mejor aspecto.\n"),TP);
	TP->SetHP(TP->QueryMaxHP());
	TP->move(carcel,M_GO);
	return 1;
}
