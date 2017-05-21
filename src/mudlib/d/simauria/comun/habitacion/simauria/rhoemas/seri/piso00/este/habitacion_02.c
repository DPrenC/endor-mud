/***************************************************************************************
 ARCHIVO:	habitacion_02.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitación este 02
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
  SetIntShort("una habitación");
  SetIntLong(W("Esta es la típica habitación de un aprendiz. Básicamente son "
  	"paredes y una cama, con lo que quiera poner su dueño. Parece que el de "
  	"esta no está por la labor de decorarla, no hay nada más.\n"));
  AddDetail(({"cama","colchón","colchon"}),W("Hay una cama simple pero funcional "
  	"pegada a una de las paredes.\n"));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Está muy limpio y algo frío.\n");
  AddDetail(({"techo"}),W("El techo está hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de roca gris. No hay "
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
