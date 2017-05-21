/***************************************************************************************
 ARCHIVO:	casa_05.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Casa de un kender.
 MODIFICACION:  20-04-2003 [z] Cambio lo de saltar para que puedan todos porque ahora
 			    es parte de un quest.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el rumor de la calle.\n");
  SetIntSmell("Hueles el aroma de las flores en primavera.\n");

  SetIntShort("una casa de la calle Kendarg");
  SetIntLong("Est�s dentro de la casa. Es una casa bastante modesta, pero "
  	"curiosa. En las paredes hay colgados varios instrumentos de m�sica, "
  	"un la�d, una flauta... No hay muchos muebles, solo una cama y una "
  	"peque�a mesa. No encuentras donde sentarte. Al fondo hay una ventana "
  	"que da a la parte trasera.\n");

  AddDetail(({"pared"}),"En la pared hay varios instrumentos colgados: un "
  	"la�d, una flauta...\n");
  AddDetail(({"ventana"}),"Es una peque�a ventana que da a la parte trasera "
  	"de la casa.\n");
  AddDetail(({"mesa"}),"Es una peque�a mesa de madera, hay una vela encima de "
  	"la mesa.\n");
  AddDetail(({"cama"}),"Es una cama peque�a, y esta hecha.\n");
  AddDetail(({"laud","la�d"}),"Un viejo y peque�o laud. Est� gastado por el uso.\n");
  AddDetail(({"flauta"}),"Una flauta de madera gastada por el uso.\n");

  AddRoomCmd("saltar","fsaltar");

  AddExit("norte",FLENHAB+"calles/kendarg_02");
}

int fsaltar(string str)
{
	if (str=="por la ventana" || str=="por ventana")
	{
		write("Abres la ventana y saltas hasta la otra parte. Nada m�s pasar "
		"la ventana se cierra de golpe.\n");
		say(CATP+" abre la ventana y salta hasta la otra parte. Nada m�s "
		"pasar la ventana se cierra de golpe.\n",TP);
		TP->move(FLENHAB+"calles/callejon_02",M_GO);
		return 1;
	}
	else
	{
		write("�Saltar por <d�nde>?\n");
		return 1;
	}
}