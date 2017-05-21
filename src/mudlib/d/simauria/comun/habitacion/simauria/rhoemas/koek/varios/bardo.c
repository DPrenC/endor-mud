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
  SetIntLong(W("Esta es la casa del bardo, Kiran. No es una casa muy ostentosa, m�s bien una "
  	"peque�a caba�a de madera a las afueras del centro del pueblo. Tiene una gran "
  	"mesa llena de papeles donde el bardo se concentra e intenta componer nuevas "
  	"obras para llenar los oidos de los habitantes de Koek. Tambi�n puedes ver un "
  	"gran ba�l.\n"));
  AddDetail(({"mesa"}),W("Es una mesa muy grande de madera un tanto oscura. Est� llena "
  	"de papeles escritos con composiciones y un tintero con su pluma.\n"));
  AddDetail(({"tintero","pluma"}),W("En la mesa puedes ver un tintero y una pluma con "
  	"algo de tinta. Parece que es la herramienta de trabajo del bardo.\n"));
  AddDetail(({"baul","ba�l","gran baul","gran ba�l"}),W("Hay un ba�l abierto a los "
  	"pies de la cama, pero est� vacio. Parece que ah� guarda el bardo sus instrumentos.\n"));
  AddDetail(({"cama"}),"Es de lo m�s normal, y parece muy c�moda.\n");
  AddDetail(({"papeles"}),W("Son composiciones que Kiran ha hecho en sus horas de duro "
  	"trabajo con un poco de ayuda por parte de las musas. Quiz�s puedas leer algunos.\n"));
  AddReadMsg(({"composici�n","composiciones","papel","papeles"}),W("Son composiciones que "
  	"Kiran ha hecho en sus horas de duro trabajo con un poco de ayuda por parte de las "
  	"musas. Quiz�s puedas leer algunos.\n"));
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
		write(W("No ser�a muy bonito por tu parte quitarle el trabajo de toda "
			"su vida a Kiran. Tienes tantos remordimientos que decides no "
			"coger eso.\n"));
		say(W("Parece que "+CATP+" va a coger los papeles de la mesa, pero "
			"lo piensa mejor y no lo hace.\n"),TP);
		return 1;
	}
}
