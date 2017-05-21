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
  SetIntSmell("Huele a algo muy extraño y no muy agradable.\n");

  SetIntShort("la casa del Shamán");
  SetIntLong("Esta es la casa del shaman. Es un lugar bastante extraño. "
  	"Hay estanterías repletas de frascos, libros y artilugios de diversas "
  	"formas y colores. Al fondo hay una gran marmita en el fuego. De ella "
  	"sale un humo que cambia de color a cada instante, y desaparece por la "
  	"chimenea. Las pocas ventanas que hay están cerradas. La estancia está "
  	"iluminada solo con unas antorchas, que hacen el lugar aún más misterioso.\n");

  AddDetail(({"ventana"}),"Una ventana de madera. Está cerrada.\n");
  AddDetail(({"antorcha"}),"Una antorcha encendida ilumina la estancia.\n");
  AddDetail(({"humo"}),"Es un humo muy extraño. Cambia de color contínuamente.\n");
  AddDetail(({"chimenea"}),"Una vieja chimenea de piedra y barro por la que sale "
  	"el humo de la marmita.\n");
  AddDetail(({"fuego"}),"Ves un fuego que alimentado por unos cuantos troncos "
  	"calienta la marmita.\n");
  AddDetail(({"pared"}),"En las paredes estanterías, también hay colgados diversos "
  	"objetos.\n");
  AddDetail(({"frascos"}),"Hay frascos de cristal con líquidos de todos los colores.\n");
  AddDetail(({"libros"}),"Hay varios libros que parecen muy antiguos\n");
  AddDetail(({"marmita"}),"Es una marmita de metal bastante grande. Hay un líquido "
  	"oscuro y humeante en su interior.\n");
  AddDetail(({"liquido","líquido"}),"Puajff, que asco. ¡Yo que tú no tocaría eso!\n");
  AddDetail(({"estanterias","estanterías"}),"Hay varias estanterías, estan repletas "
  	"de los objetos mas extraños. Desde frascos y botes de cristal a otros objetos "
  	"que nunca habias visto antes. No creo que debas tocar nada... Hay también varios "
  	"libros muy viejos.\n");
  AddDetail(({"suelo"}),"El suelo es de madera. Está limpio, pero cruje al pisar.\n");
  AddDetail(({"techo","arriba"}),"El techo está cubierto de telas de araña.\n");

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