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
	write("El viejo dice: �Oh s�! el terror�fico pantano de la muerte. "
		"La maldici�n ha vuelto a morarlo. Si nadie act�a estamos perdidos.\n");
	say("El viejo dice: �Oh s�! el terror�fico pantano de la muerte. "
		"La maldici�n ha vuelto a morarlo. Si nadie act�a estamos perdidos.\n",TP);
	write("[52mEl anciano aparta unos arbustos con la mano y te muestra "
		"un sendero que sigue hacia el norte.[0m\n");
	say("[52mEl anciano aparta unos arbustos con la mano y revela un "
		"sendero que sigue hacia el norte.[0m\n",TP);
	environment(TO)->AddExit("norte",FLENHAB+"pantano/pantano_00");
	return "El anciano dice: Este es el camino al pantano. Suerte y "
  		"recuerda una cosa, sin la espada sagrada no podr�s liberarnos "
 		"de la maldici�n y necesitar�s los anillos para poder cruzarlo.\n";
}

int fdar_anillo()
{
	object anillo_verde,anillo_azul;
	if (present("anillo verde",TP) || present("anillo az�l",TP))
	{
		if (!present("anillo verde",TP) || (!present("anillo az�l",TP)))
		{
			write("El anciano te dice: Veo que ya te prest� uno de los anillos. "
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
			"memoria la mia, te los deb� prestar antes.\n");
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
	write("El anciano te dice: El anillo az�l ser� la luz en "
	"tu camino, el anillo verde ser� tu invisible salvador.\n");
	say("El anciano le da un consejo susurrando a "+CATP+".\n",TP);
	return 1;
}

string fanillo()
{
	call_out("fdar_anillo",3);
	return ("El anciano te mira fijamente y sonr�e.\nEl viejo te dice: Da la "
		"casualidad que dichos anillos de protecci�n est�n en mi poder, "
		"y como actualmente no los necesito te los podr�a prestar para "
		"que realices tu misi�n.\n");
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
  	"Seguro que tiene m�s edad que la que aparenta.\n");
  /*
  AddQuestion(({"anillo","anillos"}),SF(fanillo));
  AddQuestion(({"pantano","pantano de la muerte"}),SF(fpantano));
  */
  AddQuestion(({"kendarg","heroe","h�roe"}),"El viejo dice: �Ah s�! Kendarg, "
  	"el h�roe local. �l nos liber� una vez de la maldici�n del pantano, pero "
  	"la maldici�n ha vuelto...\n");
  AddQuestion(({"maldicion","maldici�n","maldicion del pantano","maldici�n del pantano"}),
	"El viejo dice: La maldici�n es un espectro maligno condenado a vagar por "
	"toda la eternidad. Kendarg nos liber� una vez de ella, gracias a la espada "
	"sagrada. Pero la maldici�n ha vuelto, y el terror volver� a la regi�n.\n");
  AddQuestion(({"espectro","espectro del pantano"}),"El espectro del pantano de la muerte "
  	"es un ser et�reo que nos atormenta. S�lo Kendarg ha podido acabar con �l, pero "
  	"ha regresado.\n");
  AddQuestion(({"espada","espada sagrada","kimera"}),"El viejo dice: se cuenta que "
  	"Kendarg destruy� al espectro con una espada sagrada de confecci�n �lfica. "
  	"Cuentan tambi�n que dicha espada lleva una gema de color verde incrustada "
  	"en su empun�dura, sin la cual no tiene poder. Mis �ltimas noticias son que "
  	"Kendarg a�n la tiene en su poder.\n");

  InitChats(10,({
	"El anciano observa el lago ensimismado.\n",
	"El anciano lanza la ca�a y espera pacientemente a que pique algun pez.\n",
	"El anciano dice: Esta regi�n es peligrosa, cerca de aqu� se encuentra el "
		"pantano de la muerte. Cuentan que la maldici�n ha vuelto a habitarlo.\n",
	"El anciano murmura: Ojal� Kendarg nos librara de la maldici�n.\n",
	"El anciano comenta: Vaya, parece que hoy no tendr� suerte pescando.\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="pantano de la muerte")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
