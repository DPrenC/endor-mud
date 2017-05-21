/***************************************************************************************
 ARCHIVO:	alcaldia_arriba.c
 AUTOR:		[z] Zomax
 FECHA:		17-12-2001
 COMENTARIOS:	Alcaldía, primer piso, despacho del alcalde
 ***************************************************************************************/

#include "path.h"
inherit SCHEDULER_ROOM;
#include RHOEPRESO

int fcoger(string str)
{
	if ( str=="libro" || str=="libros" || str=="documento" || str=="documentos")
	{
		string rhoeart;
		switch (str)
		{
			case "libro":		rhoeart="un"; break;
			case "libros":		rhoeart="unos"; break;
			case "documento":	rhoeart="un"; break;
			case "documentos":	rhoeart="unos"; break;
			default:	rhoeart="un"; break;
		}
		write(W("Um... mejor que no lo cojas. No es tuyo, y no te serviría "
			"de mucho, está en una jerga muy legal. Sin embargo para "
			"las personas que trabajan aquí es algo bastante importante.\n"));
		say(W("Parece que "+CATP+" intenta coger "+rhoeart+" "+str+", pero "
			"se lo piensa mejor y desiste.\n"),TP);
		return 1;
	}
}

int fnada(string str)
{
	write("Zzzzzzzzzzzz. Sueñas con las maravillosas aventuras que te esperan.\n");
	say(W(CATP+" está dormido. Parece que sueña.\n"),TP);
	return 1;
}

int ffin()
{
	remove_action("",TP);
	write("Te despiertas... te sientes mucho mejor ahora.\n");
	say(W(CATP+" se despierta tras el largo sueño. Ahora tiene mejor cara.\n"),TP);
	return 1;
}

int faccion(int time)
{
	add_action("fnada","",1);
	call_out("ffin",time);
	TP->SetTP(TP->QueryMaxTP());
	return 1;
}


int fleer(string str)
{
	if (str=="documento" || str=="documentos" || str=="libro" || str=="libros")
	{
		string art;
		if (str=="documento" || str=="documentos")
		{
			art="el";
		}
		else
		{
			art="los";
		}
		write(W("Empiezas a leer "+art+" "+str+". Es una jerga legal incomprensible "
		"pero que funciona de maravilla con el insomnio. Notas como te estás quedando "
		"dormido...\n"));
		say(W(CATP+" se pone a leer algo y se duerme. Parece que está descansando "
		"mucho.\n"),TP);
		faccion(25);
		return 1;
	}
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("el despacho del alcalde");
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Este es el despacho del alcalde. Es un lugar muy bien decorado, con "
  	"una gran mesa de roble macizo donde el alcalde suele trabajar y las paredes "
  	"cubiertas con estanterías de madera llenas de libros y documentos.\n"));
  AddDetail(({"mesa","gran mesa","gran mesa de roble","mesa de roble"}),W("La mesa "
  	"donde suele trabajar el alcalde es una pieza de arte. Parece tallada toda de "
  	"una sola vez de un roble de dimensiones difíciles de creer. Sin duda la hizo "
  	"un verdadero artesano.\n"));
  AddDetail(({"pared","paredes","estanteria","estanterias","estanterías","estantería"}),W(
  	"Las paredes están forradas de estanterías con varios libros y documentos.\n"));
  AddDetail(({"libro","libros","documento","documentos"}),W("Hay libros y documentos "
  	"muy variados, pero principalmente tienen que ver con Koek y sus aspectos legales.\n"));

  carcel=(RHOEHAB("koek/varios/alcaldia"));
  AddExit("abajo",RHOEHAB("koek/varios/alcaldia"));
    SetLastDest(RHOEHAB("koek/calles/cendaf_03.c"));
    SetNotifyExits(({}));
    SetMainRoom("./alcaldia");
  AddItem(RHOEPNJ("koek/varios/gordon"),REFRESH_DESTRUCT,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("leer","fleer");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
}
