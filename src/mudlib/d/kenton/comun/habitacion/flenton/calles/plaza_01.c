/***************************************************************************************
 ARCHIVO:	plaza_01.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Plaza secundaria de Flenton
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <sounds.h>
inherit ROOM;

int empujado;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas voces y risas.\n");
  SetIntSmell("Te llega el aroma de comida. Alguien debe estar preparando algo.\n");

  SetIntShort("la plaza secundaria de Flenton");
  SetIntLong("Te encuentras en una pequeña plaza, en el centro hay una "
  	"fuente de piedra. Al nordeste está la calle Kendarg. La plaza está "
  	"rodeada de casas, al norte, este, oeste y sur. Pero entre ellas "
  	"destaca la del oeste, parece ser la casa mas importante del pueblo, "
  	"incluso mayor que la del jefe. Al sudeste hay un montón de madera "
  	"apilada al pie de una valla.\n");
  AddDetail(({"casa"}),"De entre todas las casas te destaca una que está "
  	"al oeste. Es mayor que el resto, y de construcción sólida.\n");
  AddDetail(({"valla"}),"Es una valla de madera.\n");
  AddDetail(({"madera","monton de madera"}),"Ves un montón de madera "
  	"apilada junto a la valla.\n");
    AddRoomCmd("empujar","fempujar");
    AddRoomCmd("entrar","fentrar");
    AddItem(OTRO("flenton/fuente2"));
    AddExit("norte",FLENHAB+"casas/casa_08");
    AddExit("sur",FLENHAB+"casas/casa_09");
    AddExit("este",FLENHAB+"casas/casa_07");
    AddExit("oeste",FLENHAB+"casas/kendarg");
    AddExit("nordeste",FLENHAB+"calles/kendarg_04");
    AddItem(FLENPNJ+"poblado/ninyo",REFRESH_DESTRUCT,1);
    AddItem(FLENPNJ+"poblado/felu",REFRESH_DESTRUCT,1);
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

int fempujar(string str)
{
	if ((str=="montón de madera")|(str=="madera"))
	{
		if(!(empujado))
		{
			write("Empujas el montón de madera y ves que "
			"ocultaba un agujero en la valla.\n");
			say(CATP+" empuja un montón de madera.\n");
			empujado=1;
			return 1;
		}
		else
		{
			write("Empujas el montón de madera y ocultas "
			"el agujero de la valla.\n");
			say(CATP+" empuja un montón de madera.\n");
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
			TP->move(FLENHAB+"calles/callejon_00",M_GO);
			say(CATP+" sale del agujero de la valla.\n");
		}
		else
		{
			write("No puedes ver ningún agujero por el que puedas "
			"pasar.\n");
		}
		return 1;
	}
}