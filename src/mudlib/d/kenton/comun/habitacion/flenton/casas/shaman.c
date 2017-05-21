/***************************************************************************************
 ARCHIVO:	shaman.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	La casa del shaman
 ***************************************************************************************/

#include "path.h"
#define KIONIX "/d/lad-laurelin/comun/quest/gardil/kionix"
#include <sounds.h>


inherit ROOM;

object shaman;
int apagada;

public int QueryTiendaShaman() { return 1; }

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el burbujeo de la marmita.\n");
  SetSoundEnvironment(SND_AMBIENTES("burbujas"), 50);
  SetIntSmell("Huele a algo muy extra�o y no muy agradable.\n");

  SetIntShort("la casa del Sham�n");
  SetIntLong("Esta es la casa del shaman. Es un lugar bastante extra�o. "
  	"Hay estanter�as repletas de frascos, libros y artilugios de diversas "
  	"formas y colores. Al fondo hay una gran marmita en el fuego. De ella "
  	"sale un humo que cambia de color a cada instante, y desaparece por la "
  	"chimenea. Las pocas ventanas que hay est�n cerradas. La estancia est� "
  	"iluminada solo con unas antorchas, que hacen el lugar a�n m�s misterioso.\n");

  AddDetail(({"ventana"}),"Una ventana de madera. Est� cerrada.\n");
  AddDetail(({"antorcha"}),"Una antorcha encendida ilumina la estancia.\n");
  AddDetail(({"humo"}),"Es un humo muy extra�o. Cambia de color cont�nuamente.\n");
  AddDetail(({"chimenea"}),"Una vieja chimenea de piedra y barro por la que sale "
  	"el humo de la marmita.\n");
  AddDetail(({"fuego"}),"Ves un fuego que alimentado por unos cuantos troncos "
  	"calienta la marmita.\n");
  AddDetail(({"pared"}),"En las paredes estanter�as, tambi�n hay colgados diversos "
  	"objetos.\n");
  AddDetail(({"frascos"}),"Hay frascos de cristal con l�quidos de todos los colores.\n");
  AddDetail(({"libros"}),"Hay varios libros que parecen muy antiguos\n");
  AddDetail(({"marmita"}),"Es una marmita de metal bastante grande. Hay un l�quido "
  	"oscuro y humeante en su interior.\n");
  AddDetail(({"liquido","l�quido"}),"Puajff, que asco. �Yo que t� no tocar�a eso!\n");
  AddDetail(({"estanterias","estanter�as"}),"Hay varias estanter�as, estan repletas "
  	"de los objetos mas extra�os. Desde frascos y botes de cristal a otros objetos "
  	"que nunca habias visto antes. No creo que debas tocar nada... Hay tambi�n varios "
  	"libros muy viejos.\n");
  AddDetail(({"suelo"}),"El suelo es de madera. Est� limpio, pero cruje al pisar.\n");
  AddDetail(({"techo","arriba"}),"El techo est� cubierto de telas de ara�a.\n");

  AddRoomCmd("encender","fencender");
  AddRoomCmd("apagar","fapagar");

  AddExit("sur",FLENHAB+"calles/sendero_02");
  AddItem(KIONIX, REFRESH_DESTRUCT, 1);
}

int fencender(string str)
{
	if ((str=="antorcha")|(str=="la antorcha"))
	{
		if (!apagada)
		{
			write("La antorcha ya estaba encendida.\n");
		}
		else
		{
			apagada=0;
			write("Enciendes la antorcha.\n");
			SetIntBright(80);
			AddDetail(({"antorcha"}),"Una antorcha encendida ilumina "
				"la estancia.\n");
		}
		return 1;
	}
	return 0;
}

int fapagar(string str)
{
	if ((str=="antorcha")|(str=="la antorcha"))
	{
		if (apagada)
		{
			write("La antorcha ya estaba apagada.\n");
		}
		else
		{
			apagada=1;
			write("Apagas la antorcha.\n");
			SetIntBright(1);
			AddDetail(({"antorcha"}),"Una antorcha apagada.\n");
		}
		return 1;
	}
	return 0;
}