/***************************************************************************************
 ARCHIVO:	callejon_00.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Callej�n
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

int empujado;

string fagujero()
{
	if (!empujado)
		return "Ves un agujero en la valla. Est� bloqueado por "
		"fuera por un mont�n de madera.\n";
	else
		return "Ves un agujero en la valla, podr�as caver por �l.\n";
}

create() {
  ::create();

  SetIndoors(0);
  SetIntBright(-10);
  SetLocate("flenton");
  SetIntNoise("Oyes el rumor de la calle tras la valla.\n");
  SetIntSmell("No huele a nada en especial.\n");

  SetIntShort("un callej�n oscuro");
  SetIntLong("Est�s en un callej�n oscuro. Est� detr�s de las casas de "
  	"la calle Kendarg. Al norte ves la pared de una casa. Al sur est� "
  	"la empalizada de madera que rodea al poblado. Al noroeste est� la "
  	"valla por la que has entrado. El callej�n contin�a hacia el este.\n");

  AddDetail(({"empalizada"}),"Es la empalizada de madera que rodea a todo el poblado.\n");
  AddDetail(({"madera","monton de madera","mont�n de madera"}),"Es la empalizada "
  	"de madera que rodea a todo el poblado.\n");
  AddDetail(({"pared"}),"Es una pared de piedra y barro. Parece bastante solida.\n");
  AddDetail(({"valla"}),"Es una valla de madera. Hay un agujero en ella.\n");
  AddDetail(({"suelo"}),"El suelo est� bastante sucio. Hay un barril junto a la empalizada.\n");
  AddDetail(({"barril"}),"Es un barril de vino. Parece vacio.\n");
  AddDetail(({"agujero"}),SF(fagujero));

  AddRoomCmd("empujar","fempujar");
  AddRoomCmd("entrar","fentrar");

  AddExit("este",FLENHAB+"calles/callejon_01");
}

int fempujar(string str)
{
	if ((str=="mont�n de madera")|(str=="madera"))
	{
		if(!(empujado))
		{
			write("Empujas el mont�n de madera y ves que "
			"ocultaba un agujero en la valla.\n");
			say(CATP+" empuja un mont�n de madera.\n");
			empujado=1;
			return 1;
		}
		else
		{
			write("Empujas el mont�n de madera y ocultas "
			"el agujero de la valla.\n");
			say(CATP+" empuja un mont�n de madera.\n");
			empujado=0;
			return 1;
		}
	}
}

int fentrar(string str)
{
	if (str=="agujero")
	{
		if(empujado)
		{
			write("Entras en el agujero de la valla.\n");
			TP->move(FLENHAB+"calles/plaza_01",M_GO);
			say(CATP+" sale del agujero de la valla.\n");
		}
		else
		{
			write("No puedes ver ning�n agujero por el que puedas "
			"pasar.\n");
		}
		return 1;
	}
}