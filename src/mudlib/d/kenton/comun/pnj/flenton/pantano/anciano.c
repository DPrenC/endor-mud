/***************************************************************************************
 ARCHIVO:	anciano.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	El anciano que ayuda en la quest
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit NPC;
/*
string fpantano()
{
	write("El viejo dice: ¡Oh sí! el terrorífico pantano de la muerte. "
		"La maldición ha vuelto a morarlo. Si nadie actúa estamos perdidos.\n");
	say("El viejo dice: ¡Oh sí! el terrorífico pantano de la muerte. "
		"La maldición ha vuelto a morarlo. Si nadie actúa estamos perdidos.\n",TP);
	write("[52mEl anciano aparta unos arbustos con la mano y te muestra "
		"un sendero que sigue hacia el norte.[0m\n");
	say("[52mEl anciano aparta unos arbustos con la mano y revela un "
		"sendero que sigue hacia el norte.[0m\n",TP);
	environment(TO)->AddExit("norte",FLENHAB+"pantano/pantano_00");
	return "El anciano dice: Este es el camino al pantano. Suerte y "
  		"recuerda una cosa, sin la espada sagrada no podrás liberarnos "
 		"de la maldición y necesitarás los anillos para poder cruzarlo.\n";
}

int fdar_anillo()
{
	object anillo_verde,anillo_azul;
	if (present("anillo verde",TP) || present("anillo azúl",TP))
	{
		if (!present("anillo verde",TP) || (!present("anillo azúl",TP)))
		{
			write("El anciano te dice: Veo que ya te presté uno de los anillos. "
			"Toma el que te falta.\n");
			say("El anciano le da un anillo a "+CATP+".\n",TP);
			if (present("anillo verde",TP))
			{
				anillo_azul=clone_object(FLENPRT+"anillo_azul");
				anillo_azul->move(TP,M_SILENT);
			}
			else
			{
				anillo_verde=clone_object(FLENPRT+"anillo_verde");
				anillo_verde->move(TP,M_SILENT);
			}
		}
		else
		{
			write("El anciano te dice: Veo que ya tienes los anillos, maldita "
			"memoria la mia, te los debí prestar antes.\n");
			say("El anciano le dice algo a "+CATP+" pero no le da nada.\n",TP);
		}
	}
	else
	{
		write("El anciano te da dos anillos\n");
		say("El anciano le da algo a "+CATP+".\n",TP);
		anillo_verde=clone_object(FLENPRT+"anillo_verde");
		anillo_azul=clone_object(FLENPRT+"anillo_azul");
		anillo_verde->move(TP,M_SILENT);
		anillo_azul->move(TP,M_SILENT);
	}
	write("El anciano te dice: El anillo azúl será la luz en "
	"tu camino, el anillo verde será tu invisible salvador.\n");
	say("El anciano le da un consejo susurrando a "+CATP+".\n",TP);
	return 1;
}

string fanillo()
{
	call_out("fdar_anillo",3);
	return ("El anciano te mira fijamente y sonríe.\nEl viejo te dice: Da la "
		"casualidad que dichos anillos de protección están en mi poder, "
		"y como actualmente no los necesito te los podría prestar para "
		"que realices tu misión.\n");
}
*/
create(){
  ::create();
  SetStandard("un anciano pescando en el lago","humano",50,GENERO_MASCULINO);
  SetIds(({"anciano","humano","pescador","viejo"}));
  SetDex(40);
  SetCon(45);
  SetInt(60);
  SetHP(QueryMaxHP());

  SetShort("un anciano pescando en el lago");
  SetLong("Ves un anciano humano pescando en el lago. Parece tener una "
  	"avanzada edad, pero es increible la vitalidad y fortaleza que aparenta, "
  	"a pesar de su pelo blanco y la red de arrugas que se dibujan en su cara. "
  	"Seguro que tiene más edad que la que aparenta.\n");
  /*
  AddQuestion(({"anillo","anillos"}),SF(fanillo));
  AddQuestion(({"pantano","pantano de la muerte"}),SF(fpantano));
  */
  AddQuestion(({"kendarg","heroe","héroe"}),"El viejo dice: ¡Ah sí! Kendarg, "
  	"el héroe local. Él nos liberó una vez de la maldición del pantano, pero "
  	"la maldición ha vuelto...\n");
  AddQuestion(({"maldicion","maldición","maldicion del pantano","maldición del pantano"}),
	"El viejo dice: La maldición es un espectro maligno condenado a vagar por "
	"toda la eternidad. Kendarg nos liberó una vez de ella, gracias a la espada "
	"sagrada. Pero la maldición ha vuelto, y el terror volverá a la región.\n");
  AddQuestion(({"espectro","espectro del pantano"}),"El espectro del pantano de la muerte "
  	"es un ser etéreo que nos atormenta. Sólo Kendarg ha podido acabar con él, pero "
  	"ha regresado.\n");
  AddQuestion(({"espada","espada sagrada","kimera"}),"El viejo dice: se cuenta que "
  	"Kendarg destruyó al espectro con una espada sagrada de confección élfica. "
  	"Cuentan también que dicha espada lleva una gema de color verde incrustada "
  	"en su empunñdura, sin la cual no tiene poder. Mis últimas noticias son que "
  	"Kendarg aún la tiene en su poder.\n");

  InitChats(10,({
	"El anciano observa el lago ensimismado.\n",
	"El anciano lanza la caña y espera pacientemente a que pique algun pez.\n",
	"El anciano dice: Esta región es peligrosa, cerca de aquí se encuentra el "
		"pantano de la muerte. Cuentan que la maldición ha vuelto a habitarlo.\n",
	"El anciano murmura: Ojalá Kendarg nos librara de la maldición.\n",
	"El anciano comenta: Vaya, parece que hoy no tendré suerte pescando.\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="pantano de la muerte")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
