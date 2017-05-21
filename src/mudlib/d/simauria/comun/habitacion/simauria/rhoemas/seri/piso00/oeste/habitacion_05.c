/***************************************************************************************
 ARCHIVO:	habitacion_05.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitación oeste 05
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

int llave;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja, ala oeste");
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
  AddRoomCmd("buscar","fbuscar");
  AddExit("sur",RHOEHAB("seri/piso00/oeste/pasillo_00"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
  llave=1;
}

reset(){
  ::reset();
  llave=1;
}

int fcoger(string str)
{
	if (str=="cama")
	{
		write("La cama es demasiado grande para que puedas cogerla.\n");
		return 1;
	}
}

int fbuscar(string str)
{
	if (str=="llave" && llave)
	{
		object llavec;
		write(W("Buscas por todas partes y debajo de la cama encuentras "
			"una llave.\n"));
		say(W(CATP+" encuentra algo debajo de la cama.\n"),TP);
		llavec=clone_object(RHOEVAR("seri/llave_cylin"));
		llavec->move(TP,M_SILENT);
		llave=0;
		return 1;
	}
}
