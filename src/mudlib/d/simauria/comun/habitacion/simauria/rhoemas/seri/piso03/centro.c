/***************************************************************************************
 ARCHIVO:	centro.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Centro del templo, habitación del Adalid.
 MODIFICACION:  21-04-2003 Como ahora Kaleband es solo a veces agresivo meto comprobacion
 			   de ataque al tocar sus cosas.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit SIM_ROOM;

int movida,trampilla;

string ftrampilla()
{
	if (movida && !trampilla) return "Hay una trampilla en el suelo. Está cerrada.\n";
	else if (movida && trampilla) return "Hay una trampilla en el suelo. Está abierta.\n";
	else return "No ves nada de eso.\n";
}

string fcama()
{
	if (movida) return W("La cama está apartada hacia un lado de su posición normal "
		"descubriendo una trampilla.\n");
	else return W("La cama es grandiosa. Después de tanto viaje no logras controlar "
		"la tentación y te intentas acostar un rato, pero apenas te apoyas notas "
		"como se mueve y te reincorporas al segundo. Que raro...\n");
}

int fabajo()
{
	if (trampilla)
	{
		int i;
		object *gente;

		gente=TP->QueryFollowers();
		if (gente)
			for(i=0;i<sizeof(gente);i++)
			{
				if (gente[i] && gente[i]->QueryIsPlayer())
				{
					if (gente[i]->Query(P_IS_FOLLOWER))
						gente[i]->Set(P_IS_FOLLOWER,FOLLOW_NO);
					gente-=({gente[i]});
				}
			}
		TP->move(RHOEHAB("seri/piso02/centro/centro"),M_GO);
		tell_room(TO,"La trampilla se cierra.\n");
		trampilla=0;
		RemoveExit("abajo",1);
		return 1;
	}
	else return "La trampilla no está abierta.\n",0;
}

reset(){
  ::reset();
  movida=0;
  trampilla=0;
  RemoveExit("abajo");
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, tercer piso, centro");
  SetIntShort("la habitación del adalid");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en la habitación de Kaleband, el adalid del templo, que rige "
  	"los destinos de todos los fieles. Esta habitación nada tiene que ver con el "
  	"resto del templo, está repleta de vasijas y encajes y todo tipo de comodidades "
  	"que tanto echabas de menos al visitar las demás habitaciones. Hay una enorme "
  	"cama con sábanas de seda amarillas y azules que parece muy cómoda.\n"));
  AddDetail(({"sabana","sabanas","sábana","sábanas"}),W("Son de una seda muy "
  	"cara, sin duda, además de bonitas son de buena calidad y resistentes. Es lo "
  	"bueno de ser el adalid.\n"));
  AddDetail(({"vasija","vasijas","encaje","encajes"}),W("Hay muchas vasijas y encajes "
  	"bajo ellas en todas partes, la mayoría como elementos decorativos.\n"));
  AddDetail(({"trampilla"}),SF(ftrampilla));
  AddDetail(({"cama","enorme cama"}),SF(fcama));
  AddRoomCmd("mover","fmover");
  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("cerrar","fcerrar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("reiniciar","freiniciar");
  AddExit("salir",RHOEHAB("seri/piso03/entrada"));
  AddItem(RHOEPNJ("seri/adalid"),REFRESH_DESTRUCT,1);
}

int freiniciar(string str)
{
	write("No, no... eso no se hace.\n");
	return 1;
}

int fcoger(string str)
{
	if (str=="vasija" || str=="vasijas" || str=="encaje" || str=="encajes")
	{
		write(W("Si crees que te dejarán salir viv"+AO+" habiendo robado al adalid "
			"es que deliras, mejor dejas todo como estaba.\n"));
		return 1;
	}
	else if (str=="sabana" || str=="sabanas" || str=="sábana" || str=="sábanas")
	{
		write("Son muy bonitas, pero están usadas, así que decides no cogerlas.\n");
		return 1;
	}
	else if (str=="cama" || str=="enorme cama")
	{
		write("Es una ENORME cama, como mucho podrías moverla.\n");
		return 1;
	}
	else if (str=="trampilla" && trampilla)
	{
		write("De paso ves a ver si puedes coger también las paredes, anda...\n");
		return 1;
	}
	else if (str=="pared" || str=="paredes")
	{
		write("¡¡¿Pero tú estás bien?!!\n");
		say(W(CATP+" está empezando a desvariar.\n"),TP);
		return 1;
	}
}

int fabrir(string str)
{
	if (str=="trampilla" && movida && trampilla)
	{
		write("La trampilla ya está abierta.\n");
		AddExit("abajo",SF(fabajo));
		return 1;
	}
	else if (str=="trampilla" && movida && !trampilla)
	{
		write("Abres la trampilla con cuidado.\n");
		AddExit("abajo",SF(fabajo));
		trampilla=1;
		return 1;
	}
}

int fcerrar(string str)
{
	if (str=="trampilla" && movida && trampilla)
	{
		write("Cierras la trampilla.\n");
		say(W(CATP+" cierra la tampilla.\n"),TP);
		RemoveExit("abajo");
		trampilla=0;
		return 1;
	}
	else if (str=="trampilla" && movida && !trampilla)
	{
		write("La trampilla ya estaba cerrada.\n");
		return 1;
	}
}

int fmover(string str)
{
	if (str=="cama" || str=="enorme cama")
	{
		object kaleband=present("kaleband",TO);
		if (kaleband && living(kaleband))
		{
			kaleband->Kill(TP);
			write(W("A Kaleband no le ha gustado que toques sus cosas y sin darte tiempo a "
			"mover la cama te ataca.\n"));
			say(W("A Kaleband no le ha gustado que "+CATP+" toque sus cosas y sin darle tiempo "
			"a mover la cama le ataca.\n"),TP);
			return 1;
		}
		if (movida)
		{
			write("Mueves la cama a su posición normal.\n");
			say(W(CATP+" mueve la cama a su posición normal.\n"),TP);
			movida=0;
			trampilla=0;
		}
		else
		{
			write(W("Mueves la cama hacia un lado y descubres en el suelo "
				"una trampilla.\n"));
			say(W(CATP+" mueve la cama hacia un lado y descubre en el suelo "
				"una trampilla.\n"));
			movida=1;
		}
		return 1;
	}
	else
	{
		notify_fail("¿Mover qué?\n");
		return 0;
	}
}
