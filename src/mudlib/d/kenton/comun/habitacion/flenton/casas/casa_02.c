/***************************************************************************************
 ARCHIVO:	casa_02.c
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
  SetIntNoise("Escuchas un perro ladrando.\n");
  SetIntSmell("Huele a quemado. Espero que nadie se haya dejado nada al fuego...\n");

  SetIntShort("una casa en la Calle del Jefe");
  SetIntLong("Estás dentro de la casa. Es una casa amplia y acogedora. En "
  	"la pared hay colgados un arco y varias pieles de animales. Junto a "
  	"la pared hay una mesa y un par de sillas. Al fondo hay una chimenea "
  	"y una cama.\n");

  AddDetail(({"pared"}),"En la pared hay colgado un arco, y también varias "
  	"pieles de animales.\n");
  AddDetail(({"arco"}),"Es un arco corriente, sin adornos.\n");
  AddDetail(({"pieles"}),"Ves diversas pieles de animales colgadas en la pared.\n");
  AddDetail(({"ventana"}),"Es una ventana de madera, esta cubierta por una cortina.\n");
  AddDetail(({"cortina"}),"Es una cortina hecha de tela, esta algo gastada.\n");
  AddDetail(({"mesa"}),"Es una mesa de tamaño medio. Encima hay platos, vasos.\n");
  AddDetail(({"silla"}),"Es una silla pequeña de madera.\n");
  AddDetail(({"cama"}),"Es una cama pequeña, y esta hecha.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera.\n");
  AddDetail(({"chimenea"}),"Es una chimenea de piedra. Hay varios troncos apilados "
  	"en su interior. Está apagada.\n");
  AddDetail(({"fuego"}),"El fuego chisporrotea y arde iluminando toda la habitación.\n");
  AddDetail(({"alfombra"}),"Ves una gran alfombra con adornos muy extraños.\n");

  AddRoomCmd("encender","fencender");
  AddRoomCmd("apagar","fapagar");

  AddExit("sur",FLENHAB+"calles/jefe_01");
  AddItem(FLENPNJ+"poblado/viejo",REFRESH_DESTRUCT);
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