/***************************************************************************************
 ARCHIVO:	bardo.c
 AUTOR:		[z] Zomax
 FECHA:		23-12-2001
 COMENTARIOS:	La casa del bardo
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO
int canya;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la casa del bardo");
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Esta es la casa del bardo, Kiran. No es una casa muy ostentosa, más bien una "
  	"pequeña cabaña de madera a las afueras del centro del pueblo. Tiene una gran "
  	"mesa llena de papeles donde el bardo se concentra e intenta componer nuevas "
  	"obras para llenar los oidos de los habitantes de Koek. También puedes ver un "
  	"gran baúl.\n"));
  AddDetail(({"mesa"}),W("Es una mesa muy grande de madera un tanto oscura. Está llena "
  	"de papeles escritos con composiciones y un tintero con su pluma.\n"));
  AddDetail(({"tintero","pluma"}),W("En la mesa puedes ver un tintero y una pluma con "
  	"algo de tinta. Parece que es la herramienta de trabajo del bardo.\n"));
  AddDetail(({"baul","baúl","gran baul","gran baúl"}),W("Hay un baúl abierto a los "
  	"pies de la cama, pero está vacio. Parece que ahí guarda el bardo sus instrumentos.\n"));
  AddDetail(({"cama"}),"Es de lo más normal, y parece muy cómoda.\n");
  AddDetail(({"papeles"}),W("Son composiciones que Kiran ha hecho en sus horas de duro "
  	"trabajo con un poco de ayuda por parte de las musas. Quizás puedas leer algunos.\n"));
  AddReadMsg(({"composición","composiciones","papel","papeles"}),W("Son composiciones que "
  	"Kiran ha hecho en sus horas de duro trabajo con un poco de ayuda por parte de las "
  	"musas. Quizás puedas leer algunos.\n"));
  carcel=(RHOEHAB("koek/calles/folker_02"));
  AddExit("sur",RHOEHAB("koek/calles/folker_02"));
  AddItem(RHOEPNJ("koek/varios/kiran"),REFRESH_DESTRUCT,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("coger","fcoger");
  canya=1;
}

int fcoger(string str)
{
	if (str=="papel" || str=="papeles")
	{
		write(W("No sería muy bonito por tu parte quitarle el trabajo de toda "
			"su vida a Kiran. Tienes tantos remordimientos que decides no "
			"coger eso.\n"));
		say(W("Parece que "+CATP+" va a coger los papeles de la mesa, pero "
			"lo piensa mejor y no lo hace.\n"),TP);
		return 1;
	}
}
