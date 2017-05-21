/***************************************************************************************
 ARCHIVO:	centro.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Centro del templo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit SIM_ROOM;

int pergamino;

string fmesa()
{
	if (pergamino) return W("Es una mesa redonda de madera muy vieja llena de polvo "
		"con un pergamino encima.\n");
	else return "Es una mesa redonda de madera muy vieja llena de polvo.\n";
}

create () {
  ::create();

  SetIndoors(1);
  Set(P_TPORT,0);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja");
  SetIntShort("una rec�ndita sala");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Est�s en una sala completamente cerrada sin puertas ni ventanas ni ninguna "
  	"salida salvo una escalera de cuerda que sube hacia arriba. Es algo as� como un "
  	"escondite o pasadizo secreto que no ha sido visitado desde hace muchos muchos a�os, "
  	"a juzgar por la cantidad de polvo y telara�as que hay por todas partes. En medio de "
  	"la sala hay una peque�a mesa redonda.\n"));

  AddDetail(({"mesa","mesa redonda"}),SF(fmesa));
  AddDetail(({"escalera","escalera de cuerda"}),W("Es una escalera hecha con cuerdas y "
  	"tablones de madera. Desde luego es m�s estable que una simple cuerda.\n"));
  AddDetail(({"telara�a","telaranya","telara�as","telaranyas","polvo"}),W("Hay "
  	"telara�as y polvo por todas partes, se�al de que hace mucho que nadie "
  	"pasaba por aqu�.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("arriba",RHOEHAB("seri/piso01/centro/centro"));
  pergamino=0;
}

int fcoger(string str)
{
	if (str=="polvo")
	{
		write(W("�Para qu� quieres coger polvo?, mejor lo dejas no sea que seas "
			"al�rgic"+AO+".\n"));
		return 1;
	}
	else if (str=="mesa" || str=="mesa redonda")
	{
		write(W("La mesa, aunque peque�a, pesa demasiado para tener que subirla "
			"luego por la escalera de cuerda. As� que decides no cogerla.\n"));
		return 1;
	}
	else if (str=="telaranya" || str=="telaranyas" || str=="telara�a" || str=="telara�as")
	{
		write(W("No necesitas coger eso, y puedes llevarte un disgusto si viene "
			"su due�a. Quiz�s sea venenosa, as� que decides no cogerlo.\n"));
		return 1;
	}
	else if (str=="escalera" || str=="escalera de cuerda")
	{
		write(W("Muy list"+AO+". �Y c�mo crees que vas a subir?. Mejor deja de "
			"hacer tonter�as y c�ntrate.\n"));
		return 1;
	}
}