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
  SetIntShort("una recóndita sala");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en una sala completamente cerrada sin puertas ni ventanas ni ninguna "
  	"salida salvo una escalera de cuerda que sube hacia arriba. Es algo así como un "
  	"escondite o pasadizo secreto que no ha sido visitado desde hace muchos muchos años, "
  	"a juzgar por la cantidad de polvo y telarañas que hay por todas partes. En medio de "
  	"la sala hay una pequeña mesa redonda.\n"));

  AddDetail(({"mesa","mesa redonda"}),SF(fmesa));
  AddDetail(({"escalera","escalera de cuerda"}),W("Es una escalera hecha con cuerdas y "
  	"tablones de madera. Desde luego es más estable que una simple cuerda.\n"));
  AddDetail(({"telaraña","telaranya","telarañas","telaranyas","polvo"}),W("Hay "
  	"telarañas y polvo por todas partes, señal de que hace mucho que nadie "
  	"pasaba por aquí.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("arriba",RHOEHAB("seri/piso01/centro/centro"));
  pergamino=0;
}

int fcoger(string str)
{
	if (str=="polvo")
	{
		write(W("¿Para qué quieres coger polvo?, mejor lo dejas no sea que seas "
			"alérgic"+AO+".\n"));
		return 1;
	}
	else if (str=="mesa" || str=="mesa redonda")
	{
		write(W("La mesa, aunque pequeña, pesa demasiado para tener que subirla "
			"luego por la escalera de cuerda. Así que decides no cogerla.\n"));
		return 1;
	}
	else if (str=="telaranya" || str=="telaranyas" || str=="telaraña" || str=="telarañas")
	{
		write(W("No necesitas coger eso, y puedes llevarte un disgusto si viene "
			"su dueña. Quizás sea venenosa, así que decides no cogerlo.\n"));
		return 1;
	}
	else if (str=="escalera" || str=="escalera de cuerda")
	{
		write(W("Muy list"+AO+". ¿Y cómo crees que vas a subir?. Mejor deja de "
			"hacer tonterías y céntrate.\n"));
		return 1;
	}
}