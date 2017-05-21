/***************************************************************************************
 ARCHIVO:	biblioteca.c
 AUTOR:		[z] Zomax
 FECHA:		15-12-2001
 COMENTARIOS:	Biblioteca de Koek
 MODIFICACION:	21-03-2003 Se pueden coger libros, de hecho añado unos cuantos.
 			   Meto al bibliotecario para la quest de Draego.
 		08-04-2003 Le añado un par de funciones para el quest.
 ***************************************************************************************/

#include "path.h"

inherit "/room/bibl_room";
#include RHOEPRESO
#include <money.h>

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la biblioteca municipal");
  SetIntLong(W("Estás en la biblioteca municipal de Koek. Es un lugar muy "
  	"tranquilo con estanterías por todas partes repletas de libros. Hay "
  	"una pequeña mesa con varias sillas donde los lectores pueden descansar "
  	"mientras ojean los libros. La verdad es que este sitio es todo un centro del "
  	"saber.\n"));
  AddDetail(({"silla","sillas","mesa"}),W("Hay una gran mesa de madera con "
  	"varias sillas alrededor bastante cómodas para que los visitantes de "
  	"la biblioteca tengan un sitio donde leer.\n"));
  AddDetail(({"estanteria","estanterias","estantería","estanterías","pared","paredes"}),W(
  	"Hay estanterías por todas partes. Están llenas de libros.\n"));
  AddDetail(({"libro","libros"}),W("Son libros sobre la historia de Koek y sus "
  	"alrededores. Para ver los disponibles mira el cartel.\n"));
  SetTema("Historias de Koek y manuales varios");
  AddBook("zendak","La historia de Zendak",RHOETXT("libros/koek/zendak"),1);
  AddBook("mysher","Las aventuras de Mysher Vol. 1",RHOETXT("libros/koek/mysher1"),1);
  AddBook("recaudador","Manual del buen recaudador de impuestos",RHOETXT("libros/koek/recaudador"),1);
  AddBook("rueda","Manual de cómo cambiar una rueda",RHOETXT("libros/koek/rueda"),1);
  AddBook("rico","Cómo hacerse rico en Simauria",RHOETXT("libros/koek/rico"),1);
  AddBook("pesca","El arte de la pesca",RHOETXT("libros/koek/pesca"),1);
  AddItem(RHOEPNJ("koek/varios/arik"),REFRESH_DESTRUCT,1);
  carcel=(RHOEHAB("koek/calles/cendaf_03"));

  AddExit("este",RHOEHAB("koek/calles/cendaf_03"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("coger","fcogerkoek");
  AddRoomCmd("devolver","fdevolver");
  AddRoomCmd("conversar","fdecir");
  AddRoomCmd("gritar","fdecir");
  AddRoomCmd("pagar","fpagar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");

}

public int fdevolver(string str)
{
	object arik,libro;
	arik=present("arik",TO);
	libro=present("libro",TP);

	if (!str || str!="libro") return notify_fail("¿Devolver <Qué>?\n"),0;
	else
	{
		if (arik && living(arik) && libro)
		{
			libro->remove();
			write(W("Devuelves un libro al bibliotecario.\n"));
			say(W(CATP+" devuelve un libro al bibliotecario.\n"));
			TP->SetAttribute("MorosoBibliotecaKoek",0);
			return 1;
		}
		else if (!libro) return notify_fail("No tienes ningún libro para devolver.\n"),0;
		else if (arik && !living(arik)) return notify_fail("No hay nadie en condiciones para darle el "
		"libro.\n"),0;
		else if (!arik) return notify_fail("No hay nadie a quien le puedas devolver el libro.\n"),0;
	}
}

public int fpagar(string str)
{
	object dinero,arik;

	dinero=present("dinero",TP);
	arik=present("arik",TO);

	if (!TP->QueryAttribute("MorosoBibliotecaKoek"))
	{
		write(W("No debes nada en esta biblioteca.\n"));
		return 1;
	}
	else if (dinero && dinero->QueryValue()>=5000 && arik && living(arik))
	{
		write(W(MONEY_LIB->PayValueString(TP, 5000, 0, "que debías del último libro "
		"que te llevaste de la biblioteca")));
		say(W(CATP+" paga las 50 monedas de oro que debías del último libro que se llevó de la "
		"bilioteca.\n"));
		if (!dinero->QueryValue()) dinero->remove();
		TP->SetAttribute("MorosoBibliotecaKoek",0);
		return 1;

	}
	else
	{
		write(W("No tienes suficiente dinero paga pagar la deuda.\n"));
		return 1;
	}
}

public int fcogerkoek(string str){
	int moroso;

	if (str && member(TO->QueryBooks(),str)) {
		moroso=TP->QueryAttribute("MorosoBibliotecaKoek");

		if (moroso) {
			if (present("arik",TO) && living(present("arik",TO))) {
				write(W("Arik dice: Vaya vaya... tienes cuentas pendientes con esta biblioteca. "
				"Veamos... debes... ¡¡¡ 50 monedas de oro!!!.\nMucho me temo que tendrás que saldar "
				"la deuda si quieres que te preste algún otro libro. Págame cuando puedas.\n"));
				return 1;
			}
			else {
				write(W("El estante está cerrado, tendrás que esperar al bibliotecario.\n"));
				return 1;
			}
		}
		else if (!present("arik",TO) || !living(present("arik",TO))){
				write(W("El estante está cerrado, tendrás que esperar al bibliotecario.\n"));
				return 1;
		}
		else TP->SetAttribute("MorosoBibliotecaKoek",1);
		return fcoger(str);
	}
}

public int fdecir(string str)
{
	write(W("Shhhh.... no se puede hablar en la biblioteca.\n"));
	say(W("Parece que "+CATP+" va a decir algo... pero se acuerda de que está "
	"en una biblioteca y se calla.\n"),TP);
	return 1;
}
