/***************************************************************************************
 ARCHIVO:	biblioteca.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Biblioteca del templo.
 MODIFICACION:  22-04-2003 Añado funciones y manuscrito para el Quest de Draego.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit "/room/bibl_room";
int papel;

public string fladrillo()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"libro") && quest["libro",0]==5)
		quest+=(["libro":6]);
	if (quest && member(quest,"libro") && quest["libro",0]==6)
	{
		return W("Miras con cuidado el suelo en busca del ladrillo que mueva la "
		"estanteria. Parece que lo tienes localizado muy cerca de la estantería, "
		"deberías empujarlo.\n");
	}
	else return W("El suelo está hecho de ladrillos de piedra grises, como el resto "
		"del templo.\n");

}

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la biblioteca");
  SetIntLong(W("Estás en la biblioteca del templo. Esta es una gran fuente "
  	"de saber disponible para todos los miembros del templo, en la que "
  	"dejan pasar las horas para sumergirse en su aprendizaje. Hay una gran "
  	"estantería donde reposan algunos manuscritos y viejos libros.\n"));
  AddDetail(({"silla","sillas","mesa"}),W("Hay dos mesas muy largas rodeadas "
  	"de varias sillas donde se puede sentar en absoluta tranquilidad "
  	"cualquier lector.\n"));
  AddDetail(({"estanteria","estanterias","estantería","estanterías","pared","paredes"}),W(
  	"Hay estanterías por todas partes, están llenas de libros, una en concreto "
  	"muy pesada y vieja te atrae misteriosamente.\n"));
  AddDetail(({"libro","libros"}),"Hay muchos libros, de todas clases.\n");
  AddDetail(({"ladrillos","suelo","ladrillo"}),SF(fladrillo));
  SetTema("Entrenamiento Físico y Espiritual");
  AddBook("Fieles","Código de los fieles",RHOETXT("libros/seri/codigo"),0);
  AddBook("Maestros","Conjuros de los maestros",RHOETXT("libros/seri/conjuros"),0);

  AddExit("oeste",RHOEHAB("seri/piso00/centro/pasillo_04"));

  AddRoomCmd("decir","fdecir");
  AddRoomCmd("empujar","fempujar");
  papel=1;
}

public int fempujar(string str)
{
	object manuscrito;
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (!str) return 0;
	else lower_case(str);
	if (str!="ladrillo") return 0;
	else if (quest && member(quest,"libro") && quest["libro",0]==5)
	{
		write(W("Hay tantos ladrillos... primero deberias mirar un poco a ver "
		"si encuentras el que buscas.\n"));
		return 1;
	}
	else if (quest && member(quest,"libro") && quest["libro",0]==6)
		quest+=(["libro":7]);
	if (quest && member(quest,"libro") && quest["libro",0]==7)
	{
		if (papel)
		{
			write(W("Empujas el ladrillo y la estantería se abre bruscamente. Como no "
			"parece que te vaya a dar tiempo a pensartelo mucho alargas tu mano y entre "
			"la oscuridad de detrás del mueble coges lo que parece un papel.\n\nDe repente "
			"la estantería vuelve a su lugar y no te pilla la mano de milagro. Parece que "
			"tus instintos eran acertados.\n"));
			manuscrito=clone_object(RHOEVAR("seri/manuscrito"));
			manuscrito->move(TP,M_SILENT);
			papel=0;
			return 1;
		}
		else
		{
			write(W("Empujas el ladrillo y la estantería se abre bruscamente. Como no "
			"parece que te vaya a dar tiempo a pensartelo mucho alargas tu mano entre "
			"la oscuridad de detrás del mueble pero no encuentras nada. De repente te fijas "
			"en las marcas recientes del suelo, alguien acaba de estar aquí y se ha llevado "
			"lo que había... esperemos que lo devuelva... tedrás que esperar.\n"));
			return 1;
		}
	}
	return 0;
}

public int fdecir(string str)
{
	if (str)
	{
		write("Shhhh.... no se puede hablar en la biblioteca.\n");
		say(W("Parece que "+CATP+" va a decir algo... pero se acuerda de que está "
		"en una biblioteca y se calla.\n"),TP);
		return 1;
	}
}

reset(){
  ::reset();

  papel=1;
}