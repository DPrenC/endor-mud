/***************************************************************************************
 ARCHIVO:	habitacion_02.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitaci�n este 02
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
  SetIntLong(W("Esta es la t�pica habitaci�n de un aprendiz. B�sicamente son "
  	"paredes y una cama, con lo que quiera poner su due�o. Parece que el de "
  	"esta no est� por la labor de decorarla, no hay nada m�s.\n"));
  AddDetail(({"cama","colch�n","colchon"}),W("Hay una cama simple pero funcional "
  	"pegada a una de las paredes.\n"));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Est� muy limpio y algo fr�o.\n");
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. No hay "
  	"nada en ellas.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("norte",RHOEHAB("seri/piso00/este/pasillo_07"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}

int fcoger(string str)
{
	if (str=="cama")
	{
		write("La cama es demasiado grande para que puedas cogerla.\n");
		return 1;
	}
}
