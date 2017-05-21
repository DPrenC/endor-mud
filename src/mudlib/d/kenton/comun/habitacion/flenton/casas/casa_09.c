/***************************************************************************************
 ARCHIVO:	casa_09.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Casa de un kender
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

int encendida;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el rumor de la calle.\n");
  SetIntSmell("Huele a limpio.\n");

  SetIntShort("una casa de la plaza Kendarg");
  SetIntLong("Estás dentro de la casa. Parece una casa bastante antigua, "
  	"pero esta en buen estado. Hay una chimenea al fondo, y en frente "
  	"una mecedora. En un lateral hay una cama y un barril.\n");

  AddDetail(({"pared"}),"Es una pared lisa y sin adornos.\n");
  AddDetail(({"ventana"}),"Es una pequeña ventana que da a la plaza.\n");
  AddDetail(({"cama"}),"Es una cama pequeña de madera. Está hecha.\n");
  AddDetail(({"suelo"}),"El suelo es de madera.\n");
  AddDetail(({"barril"}),"Es un barril de vino vacío.\n");
  AddDetail(({"techo"}),"El techo es de paja, hay una lámpara colgando de el.\n");
  AddDetail(({"lampata","lámpara"}),"Es una lámpara de aceite.\n");
  AddDetail(({"mecedora"}),"Es una mecedora de madera. Es bastante antigua.\n");
  AddDetail(({"chimenea"}),"Es una chimenea de piedra. Hay varios troncos apilados "
	"en su interior. Está apagada.\n");

  AddRoomCmd("encender","fencender");
  AddRoomCmd("apagar","fapagar");

  AddExit("norte",FLENHAB+"calles/plaza_01");
  AddItem("/guilds/hechiceros/quest/bolafuego/ereldil",REFRESH_DESTRUCT);
}

int fencender(string str)
{
	if(str=="chimenea")
	{
		if (!encendida)
		{
			SetIntBright(95);
			write("Enciendes la chimenea y la habitación se ilumina.\n");
			say(CATP+" enciende la chimenea y la habitación se ilumina.\n",TP);
			AddDetail(({"chimenea"}),"Es una chimenea de piedra. En su "
			"interior arden varios troncos que iluminan la estancia.\n");
			return 1;
		}
		else
		{
			write("La chimenea ya estaba encendida.\n");
			return 1;
		}
	}
}

int fapagar(string str)
{
	if(str=="chimenea")
	{
		if (encendida)
		{
			SetIntBright(80);
			write("Apagas la chimenea, y comienza a humear un poco.\n");
			say(CATP+" apaga la chimenea y comienza a humear un poco.\n",TP);
			AddDetail(({"chimenea"}),"Es una chimenea de piedra. Hay varios "
			"troncos apilados en su interior. Está apagada.\n");
			return 1;
		}
		else
		{
			write("La chimenea ya estaba apagada.\n");
			return 1;
		}
	}
}