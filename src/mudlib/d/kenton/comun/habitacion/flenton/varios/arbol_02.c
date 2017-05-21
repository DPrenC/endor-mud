/***************************************************************************************
 ARCHIVO:	arbol_02.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Gran Árbol
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

int cogida;



create(){
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas la dulce y encantadora melodía que podrucen las hojas "
  	"cuando las agita el viento... parece como si una mujer cantase a través "
  	"de ellas.\n");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetIntShort("la copa del árbol");
  SetIntLong("Estás en la copa del árbol, desde aquí puedes ver aún más lejos. "
  	"El viento acaricia tu cara, y te sientes en la cima del mundo. Estás tan "
  	"contento que te entran ganas de bailar... aunque no sería una sensata idea.\n");

  AddDetail(({"rama"}),"Las ramas donde estás apoyado no son muy fuertes...\n");
  AddDetail(({"hojas"}),"Ves como el viento agita las hojas de la copa del árbol.\n");
  AddDetail(({"suelo"}),"¡Miras abajo y ves el suelo bastante lejos! debes estar al "
  	"menos a 50 metros de altura\n");
  AddDetail(({"horizonte","alrededores"}),"Miras al horizonte, desde aquí puedes "
  	"divisar todos los parajes vecinos...\n");

  AddRoomCmd("bailar","fbailar");

  AddExit("abajo",FLENHAB+"varios/arbol_01");
  AddItem(FLENVAR+"musgo_quest",REFRESH_REMOVE);
}

int fbailar()
{
	write("Comienzas a bailar y a moverte peligrosamente.\n");
	say(W(CATP+" comienza a bailar y a hacer tonterias.\n"),TP);
	call_out("farbol2",2);
	return 1;
}

int farbol2()
{
	write(W("¡Notas como una de las ramas cede, pierdes el equilibrio y "
		"comienzas a caer! Debías haber hecho caso a tu sentido comun "
		"y no hacer tonterías.\n"));
	say(W(CATP+" pierde el equilibrio y se precipita hacia el suelo.\n"),TP);
	write("Te vas arañando con las ramas al caer...\n");
	call_out("fcaida1",1);
	return 1;
}

int fcaida1()
{
	tell_room(FLENHAB+"varios/arbol_01",W("Oyes crujidos de ramas que se "
		"rompen y quejidos que provienen de la copa del árbol. Al instante, "
		"ves como alguien cae desde arriba, hacia el suelo a gran velocidad.\n"),({TP}));
	call_out("fcaida2",2);
	return 1;
}

int fcaida2()
{
	TP->move(FLENHAB+"varios/arbol_00");
	TP->SetHP((TP->QueryHP())-(random(15)+random(15)));
	write(W("Al fin llegas al suelo. No es una caída suave... ¡menudo porrazo! "
		"¡¡Ouchhh!!. Te sientes bastante dolorido y aturdido por la caída.\n"));
	say(W(CATP+" cae de repente desde el árbol como una fruta madura. ¡Menudo porrazo!\n"),TP);
	return 1;
}