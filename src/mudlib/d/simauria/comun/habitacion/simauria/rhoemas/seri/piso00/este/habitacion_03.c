/***************************************************************************************
 ARCHIVO:	habitacion_03.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitaci�n este 03
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja, ala este");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitaci�n");
  SetIntLong(W("Te encuentras en una de las habitaciones de la planta baja del templo. "
  	"Esta es una de las m�s simples, b�sicamente son cuatro paredes y una cama. "
  	"Lo �nico especial que puedes ver es una alfombra azul en el suelo, al lado "
  	"mismo de la cama.\n"));
  AddDetail(({"cama","colch�n","colchon"}),W("A un lado de la habitaci�n puedes ver "
  	"una cama muy simple hecha de madera y paja.\n"));
  AddDetail(({"alfombra"}),W("Al lado de la cama hay una alfombra tejida azul con "
  	"unas l�neas amarillas. Es bastante �til para no enfriarse los pies.\n"));
  AddDetail(({"suelo"}),W("El suelo es de roca gris. Est� muy limpio y algo fr�o. Quiz�s "
  	"por eso hay una alfombra justo al lado de la cama, para aplacar el fr�o al "
  	"levantarse.\n"));
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. No hay "
  	"nada que las decore.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("sur",RHOEHAB("seri/piso00/este/pasillo_00"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}

int fcoger(string str)
{
	if (str=="alfombra")
	{
		write(W("La alfombra est� usada y adem�s una de las patas de la "
			"cama est� sobre ella, as� que en ning�n caso podr�as cogerla.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("No puedes coger la cama, a�n siendo bastante simple es demasiado "
			"pesada para llevarla.\n"));
		return 1;
	}
}
