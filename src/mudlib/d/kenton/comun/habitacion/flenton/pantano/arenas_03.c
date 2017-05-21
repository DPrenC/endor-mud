/***************************************************************************************
 ARCHIVO:	arenas_03.c
 AUTOR:		[k] Korsario
 FECHA:		07-05-1998
 COMENTARIOS:	Arenas movedizas del pantano de la muerte.
 		27-01-2002  [z] Zomax
 		Modifico casi todas las funciones para que sean algo más complejas y no
 		haya truquitos para escapar (al menos que hayan menos) y el call_out se
 		acabe si el player consigue salir.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit ROOM;

int fhundir()
{
	switch(random(4))
	{
		case 0:	write(W("Te sigues hundiendo otro poco más, ves como la muerte "
			"acecha.\n"));
			say(W(CATP+" sigue atrapad"+AO+" en las arenas movedizas, cada vez le "
			"queda menos tiempo para salir.\n"),TP);
			break;
		case 1: write("Tus pies se hunden en el lodo otro palmo más.\n");
			say(W(CATP+" sigue atrapad"+AO+" en las arenas movedizas, parece "
			"que no conseguirá salir con vida.\n"),TP);
			break;
		case 2:	write("Sientes cómo la muerte se acerca... te hundes otro poco.\n");
			say(W(CATP+" sigue atrapad"+AO+" en las arenas movedizas, cada vez se "
			"hunde más, esta vez no lo contará.\n"),TP);
			break;
		default:write(W("Otro poco más que te hundes... seria conveniente que hicieras "
			"testamento.\n"));
			say(W(CATP+" sigue atrapad"+AO+" en las arenas movedizas, quizás deberías "
			"empezar a rezar por su alma.\n"),TP);
			break;
	}
	return 1;
}

int fsalir(string str)
{
	if(!TP->QueryAttribute("arenas")||TP->QueryGhost()||!first_inventory(TP)||present("anillo verde",TP))
	{
		TP->RemoveAttribute("arenas");
		return TP->move(FLENHAB+"pantano/pantano_0"+to_string(random(10))+".c",M_GO);
	}
	else
		return notify_fail(W("Estás atrapad"+AO+" en las arenas movedizas y eres incapaz de salir.\n")),0;
}

int fentrada()
{
	if (TP->QueryGhost()||!first_inventory(TP)) return 1;
	if(present("anillo verde",TP))
	{
		write(W("El anillo verde se ilumina por un instante y sientes "
		"que eres inmune al efecto trampa de las arenas movedizas.\n"));
		return 1;
	}
	else
	{
		if (TP->Query(P_IS_FOLLOWER)) TP->Set(P_IS_FOLLOWER,FOLLOW_NO);
		TP->SetAttribute("arenas",1);
		write(W("Al entrar notas que el terreno es mucho mas cenagoso que el "
		"resto. De repente no puedes dar un paso mas, quedas atrapad"+AO+" en el lodo.\n"));
		say(W("¡"+CATP+" ha quedado atrapad"+AO+" en las arenas movedizas!\n"),TP);
		call_out("fquitar",10);
		return 1;
	}
}

int fquitar()
{
	int vida;
	object morir;
	if (ENTP && lower_case(ENTP->QueryIntShort())!="las arenas movedizas del pantano")
	{
		remove_call_out("fquitar");
		return 1;
	}
	else if(present("anillo verde",TP))
	{
		if(present("anillo verde",TP))
		write(W("El anillo verde se ilumina por un instante y sientes que eres "
		"inmune al efecto trampa de las arenas movedizas.\n"));
		remove_call_out("fquitar");
		return 1;
	}
	else if (TP->QueryGhost())
	{
		write("Eres demasiado etéreo como para caer en las arenas movedizas.\n");
		remove_call_out("fquitar");
		return 1;
	}
	else if (!first_inventory(TP))
	{
		write(W("No llevar nada encima te ha salvado de una muerte segura al no "
		"quedar atrapad"+AO+" en las arenas movedizas.\n"));
		remove_call_out("fquitar");
		return 1;
	}
	else
	{
		fhundir();
		vida=((TP->QueryHP())-10);
		if(vida<0)
		{
			write(W("Finalmente terminas de hundirte en las entrañas de la tierra "
			"y sufres una lenta y horrible muerte.\n"));
			morir=clone_object(FLENVAR+"muerte_arenas");
			morir->move(TP,M_SILENT);
			morir->init();
			remove_call_out("fquitar");
			return 1;
		}
		else
		{
			TP->AddHP(-10);
			call_out("fquitar",10);
			return 1;
		}
	}
}

int ftirar(string str)
{
	if(str=="todo" && first_inventory(TP))
	{
		int i;
		object *cosas;
		cosas=all_inventory(TP);
		for(i=0;i<sizeof(cosas);i++)
		{
			cosas[i]->move(TO,M_SILENT);
		}
		write(W("A duras penas consigues tirar todo lo que llevas encima. Ahora pareces "
			"más liger"+AO+" y gracias a eso consigues salir de las arenas movedizas.\n"));
		say(W(CATP+" consigue tirar todo lo que tiene y así logra pesar menos y salir "
			"de las arenas movedizas.\n"),TP);
		TP->RemoveAttribute("arenas");
		remove_call_out("fquitar");
		return 1;
	}
	else if (present(str,TP))
	{
		write(W("Tiras "+present(str,TP)->QueryShort()+" rezando para que te haga sentirte más "
			"liger"+AO+" y poder salir de las arenas movedizas.\n"));
		say(W(CATP+" tira "+present(str,TP)->QueryShort()+" en un intento desesperado por salir "
			"de las arenas movedizas aligerando el peso de su bolsillo.\n"),TP);
		present(str,TP)->move(TO,M_SILENT);
		if (!first_inventory(TP))
		{
			write(W("Ahora que no llevas nada te sientes más liger"+AO+" y consigues salir de la "
				"trampa. Ufff... ha faltado poco.\n"));
			say(W(CATP+" consigue salir de las arenas por los pelos. Le ha faltado poco para morir.\n"),TP);
			TP->RemoveAttribute("arenas");
			remove_call_out("fquitar");
			return 1;
		}
		else return 1;
	}
}

int fcoger(string str)
{
	write("Todo lo que cae al suelo queda atrapado en el fango. No puedes coger nada.\n");
	return 1;
}

int fseguir(string str)
{
	if (TP->QueryAttribute("arenas"))
	{
		write(W("No puedes seguir a nadie, estás atrapad"+AO+" en las arenas movedizas.\n"));
		return 1;
	}
	else return 0;
}

create(){
   ::create();

  SetIndoors(0);
  SetLocate("pantano de la muerte");
  SetIntSmell("Huele fatal, a aguas estancadas.\n");
  SetIntNoise("Escuchas los terroríficos sonidos que hace el viento entre los árboles.\n");

  SetIntShort("las arenas movedizas del pantano");
  SetIntLong(W("Estás justo en las arenas movedizas del pantano de la muerte, uno de "
  	"sus mayores peligros. A simple vista parece un gran charco de barro, o incluso "
  	"tierra firme, pero ese es el mayor peligro que tiene, más de uno ha perdido la "
  	"vida aquí por no fijarse donde pisa.\n"));

  AddRoomCmd("tirar","ftirar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("seguir","fseguir");

  AddExit("norte",SF(fsalir));
  AddExit("sur",SF(fsalir));
  AddExit("este",SF(fsalir));
  AddExit("oeste",SF(fsalir));
  AddExit("nordeste",SF(fsalir));
  AddExit("noroeste",SF(fsalir));
  AddExit("sureste",SF(fsalir));
  AddExit("suroeste",SF(fsalir));
}

init(){
  ::init();

  call_out("fentrada",1);
}
